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
	size = GetSkeletonBoneCount();
	boneList = new Bone[size];

	if (!boneList)
		return;

	for (size_t i{0u}; i < size; ++i)
	{
		boneList[i] = std::move(Bone(i, *this));
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
		Math::Vec3 worldChild	{Math::Transform::translation(boneList[i].globalPose)};
		Math::Vec3 worldParent	{Math::Transform::translation(boneList[boneList[i].parentIndex].globalPose)};

		DrawLine(worldChild.x, worldChild.y - 25.f, worldChild.z,
				 worldParent.x, worldParent.y - 25.f, worldParent.z,
				 1.f, .0f, .0f);
	}
}

void Skeleton::MoveBone(int boneIndex, const Math::Vector3& translation) noexcept
{
	Bone* bone			= &boneList[boneIndex];
	bone->localPose.trans += translation;
	bone->globalPose	= boneList[bone->parentIndex].globalPose * bone->localPose.toMatrix4();
	bone->invBindPose	= bone->globalPose.inversed();
}