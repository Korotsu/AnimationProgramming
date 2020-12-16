#include "Skeleton.h"
#include "Bone.h"
#include "Engine.h"

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
	if (boneList)
		delete[] boneList;
}


void Skeleton::init()
{
	size = GetSkeletonBoneCount();
	boneList = new Bone[size];

	if (!boneList)
		return;

	for (size_t i{ 1u }; i < size; ++i)
	{
		boneList[i] = std::move(Bone(i, *this));
	}
}


void Skeleton::Draw() const
{
	// The last 7 bones are IK
	const size_t boneCount{size - 7u};

	for (size_t i = 1u; i < boneCount; i++)
	{
		DrawLine(boneList[i].pose.trans.x, boneList[i].pose.trans.y, boneList[i].pose.trans.z,
				 boneList[boneList[i].parent].pose.trans.x, boneList[boneList[i].parent].pose.trans.y, boneList[boneList[i].parent].pose.trans.z,
				 1.f, .0f, .0f);
	}
}