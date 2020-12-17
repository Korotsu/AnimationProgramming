#include "Skeleton.h"
#include "Bone.h"
#include "Engine.h"
#include "Vector3.h"
#include <iostream>

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

	for (size_t i{ 0u }; i < size; ++i)
	{
		boneList[i] = std::move(Bone(i, *this));
	}
}


void Skeleton::Draw() const
{
	// The last 7 bones are IK
	const size_t boneCount{ size - 7u };

	for (size_t i = 1u; i < boneCount; i++)
	{
		/*Math::vec4 worldChild{boneList[i].pose.trans};
		Math::vec4 worldParent{ boneList[boneList[i].parent].pose.trans };

		worldChild = boneList[i].invBindPos.inversed() * worldChild;
		worldParent = boneList[boneList[i].parent].invBindPos.inversed() * worldParent;

		worldChild.homogenize();
		worldParent.homogenize();*/

		//Math::mat4 worldChild  = boneList[i].pose.toMatrix() * boneList[boneList[i].parent].invBindPos.inversed();
		//Math::mat4 worldParent = boneList[boneList[i].parent].pose.toMatrix() * boneList[boneList[boneList[i].parent].parent].invBindPos.inversed();

		Math::mat4 worldChild = boneList[i].invBindPos.inversed();
		Math::mat4 worldParent = boneList[boneList[i].parent].invBindPos.inversed();

		/*DrawLine(boneList[i].pose.trans.x, boneList[i].pose.trans.y, boneList[i].pose.trans.z,
				 boneList[boneList[i].parent].pose.trans.x, boneList[boneList[i].parent].pose.trans.y, boneList[boneList[i].parent].pose.trans.z,
				 1.f, .0f, .0f);*/

		DrawLine(worldChild[12], worldChild[13], worldChild[14],
			worldParent[12], worldParent[13], worldParent[14],
			1.f, .0f, .0f);

		//std::cout << "Child  vector = x : " << worldChild.xyz.x << "; y : " << worldChild.xyz.y << "; z : " << worldChild.xyz.z << ";" << std::endl;
		//std::cout << "Parent vector = x : " << worldParent.xyz.x << "; y : " << worldParent.xyz.y << "; z : " << worldParent.xyz.z << ";" << std::endl;

		//std::cout << "Matrix inv inv xd = " << boneList[i].invBindPos << std::endl;
	}

	Math::vec3 pos;
	Math::Quaternion quat;
	GetSkeletonBoneLocalBindTransform(0, pos.x, pos.y, pos.z, quat[0], quat[1], quat[2], quat[3]);

	std::cout << "Root  vector = x : " << pos.x << "; y : " << pos.y << "; z : " << pos.z << ";" << std::endl;
}