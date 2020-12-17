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
	delete[] boneList;
}


void Skeleton::init()
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
	// The last 7 bones are IK bones
	const Bone* end{boneList + size - 7u};

	// First bone is root, ignore it
	for (Bone const* bone{boneList + 1u}; bone < end; ++bone)
	{
		//const Bone* parent{boneList + bone->parentIndex};

		Math::Vec4 childWorldPos{bone->invBindPose.inversed() * Math::Vec4{bone->pose.trans}};
		Math::Mat4 parentWorldPos{bone->invBindPose.inversed()};
		
		/* Repères XYZ
		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 childWorldPos.xyz.x + 2.5f, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 1.f, .0f, .0f);

		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 childWorldPos.xyz.x, childWorldPos.xyz.y + 2.5f, childWorldPos.xyz.z,
				 .0f, 1.f, .0f);

		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z + 2.5f,
				 .0f, .0f, 1.f);
		*/
		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 parentWorldPos[12], parentWorldPos[13], parentWorldPos[14],
				 1.f, .0f, .0f);
	}
}