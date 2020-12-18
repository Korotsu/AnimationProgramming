#include "Skeleton.h"
#include "Bone.h"
#include "Engine.h"
#include "Transform.h"

#include <utility>

/*
Skeleton::Skeleton()
	: size{GetSkeletonBoneCount()},
	  boneList{new Bone[size]}
{
	for (size_t i{1u}; i < size; ++i)
	{
		boneList[i] = std::move(Bone(i, *this));
	}
}
*/

Skeleton::~Skeleton()
{
	delete[] boneList;
}


// Skeleton is initialized here because it prevents crashes related to data races
void Skeleton::Init() noexcept
{
	size		= GetSkeletonBoneCount();
	boneList	= new Bone[size];
	palette		= new Math::Mat4[size];

	for (size_t i{0u}; i < size; ++i)
	{
		boneList[i] = std::move(Bone(i, *this));
	}
}


void Skeleton::SetBoneTransform(int boneIndex, const Math::Vector3& trans, const Math::Quaternion& rot) noexcept
{
	// Invalid bone
	if ((unsigned int)boneIndex > size)
		return;

	Bone& bone{boneList[boneIndex]};

	bone.localPose.trans	= trans;
	bone.localPose.rot		= rot;
	bone.globalPose			= bone.localPose.toMatrix4();

	if (bone.parentIndex != -1)
		bone.globalPose = boneList[bone.parentIndex].globalPose * bone.globalPose;
}


void Skeleton::Draw() const
{
	// The last 7 bones are IK
	const size_t boneCount{size - 7u};

	// The 1st bone is the root
	// The 2nd is the pelvis
	// Ignore them, since drawing the bone between these 2 joints is not useful
	for (size_t i = 2u; i < boneCount; ++i)
	{
		// Get the translation of each transform
		Math::Vec3 worldChild	{Math::Transform::translation(boneList[i].globalPose)};
		Math::Vec3 worldParent	{Math::Transform::translation(boneList[boneList[i].parentIndex].globalPose)};

		DrawLine(worldChild.x, worldChild.y, worldChild.z,
				 worldParent.x, worldParent.y, worldParent.z,
				 1.f, .0f, .0f);
	}
}


void Skeleton::GatherMatrixPalette() noexcept
{
	// The last 7 bones are IK
	const size_t end{size - 7u};
	for (size_t i{0u}; i < end; ++i)
	{
		const Bone& bone{boneList[i]};
		palette[i] = bone.globalPose * bone.invBindPose;
	}
}


void Skeleton::ApplyAnimTransform(const char* animName, size_t keyframe) noexcept
{
	if (!animName || keyframe > GetAnimKeyCount(animName))
		return;

	for (size_t i{0u}; i < size; ++i)
	{
		Math::Quaternion rot;
		Math::Vec3 pos;

		GetAnimLocalBoneTransform(animName, i, keyframe, pos.x, pos.y, pos.z, rot[0], rot[1], rot[2], rot[3]);

		SetBoneTransform(i, pos, rot);
	}
}