#include "Skeleton.h"
#include "Bone.h"
#include "Engine.h"
#include "Transform.h"
#include "Keyframe.h"

#include <utility>

Skeleton::~Skeleton() noexcept
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

	Bone& bone{ boneList[boneIndex] };

	if (bone.parentIndex != -1)
	{
		bone.localAnimPose.trans	= bone.localBindPose.trans + trans;
		bone.localAnimPose.rot		= bone.localBindPose.rot * rot;

		bone.globalAnimPose			= boneList[bone.parentIndex].globalAnimPose * bone.localAnimPose.toMatrix4();
	}

	else
	{
		bone.localAnimPose.trans = bone.localBindPose.trans + trans;
		bone.localAnimPose.rot = bone.localBindPose.rot * rot;

		bone.globalAnimPose = bone.localAnimPose.toMatrix4();
	}
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
		Math::Vec3 worldChild	{Math::Transform::translation(boneList[i].globalAnimPose)};
		Math::Vec3 worldParent	{Math::Transform::translation(boneList[boneList[i].parentIndex].globalAnimPose)};

		DrawLine(worldChild.x, worldChild.y - 25.f, worldChild.z,
				 worldParent.x, worldParent.y - 25.f, worldParent.z,
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
		palette[i] = bone.globalAnimPose * bone.invBindPose;
	}
}


void Skeleton::ApplyKeyframe(const Keyframe& keyframe) noexcept
{
	for (size_t i{0u}; i < size; ++i)
	{
		const BonePose& pose{keyframe.poses[i]};

		SetBoneTransform(i, pose.trans, pose.rot);
	}
}