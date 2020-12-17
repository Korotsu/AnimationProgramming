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
	/*// The last 7 bones are IK bones
	const Bone* end{boneList + size - 7u};

	// First bone is root, ignore it
	for (Bone const* bone{boneList + 1u}; bone < end; ++bone)
	{
		//const Bone* parent{boneList + bone->parentIndex};

		Math::Vec4 childWorldPos{bone->invBindPose.inversed() * Math::Vec4{bone->pose.trans}};
		Math::Mat4 parentWorldPos{bone->invBindPose.inversed()};
		
		 Repères XYZ
		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 childWorldPos.xyz.x + 2.5f, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 1.f, .0f, .0f);

		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 childWorldPos.xyz.x, childWorldPos.xyz.y + 2.5f, childWorldPos.xyz.z,
				 .0f, 1.f, .0f);

		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z + 2.5f,
				 .0f, .0f, 1.f);
		
		DrawLine(childWorldPos.xyz.x, childWorldPos.xyz.y, childWorldPos.xyz.z,
				 parentWorldPos[12], parentWorldPos[13], parentWorldPos[14],
				 1.f, .0f, .0f);
	}*/



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

		/*Math::mat4 worldChild = boneList[i].invBindPose.transposed();
		Math::mat4 worldParent = boneList[boneList[i].parentIndex].invBindPose.transposed();*/

		Math::mat4 worldChild  = boneList[i].globaPose;
		Math::mat4 worldParent = boneList[boneList[i].parentIndex].globaPose;

		/*DrawLine(boneList[i].pose.trans.x, boneList[i].pose.trans.y, boneList[i].pose.trans.z,
				 boneList[boneList[i].parent].pose.trans.x, boneList[boneList[i].parent].pose.trans.y, boneList[boneList[i].parent].pose.trans.z,
				 1.f, .0f, .0f);*/

		DrawLine(worldChild[12] + 100, worldChild[13], worldChild[14],
			worldParent[12] + 100, worldParent[13], worldParent[14],
			1.f, .1f, .1f);

		std::cout << "Child  vector = x : " << worldChild[12] << "; y : " << worldChild[13] << "; z : " << worldChild[14] << ";" << std::endl;
		//std::cout << "Parent vector = x : " << worldParent.xyz.x << "; y : " << worldParent.xyz.y << "; z : " << worldParent.xyz.z << ";" << std::endl;

		//std::cout << "Matrix inv inv xd = " << boneList[i].invBindPos << std::endl;
	}

	Math::vec3 pos;
	Math::Quaternion quat;

	int spineInt = 3;
	GetSkeletonBoneLocalBindTransform(spineInt, pos.x, pos.y, pos.z, quat[0], quat[1], quat[2], quat[3]);

	const char* spineParentName = GetSkeletonBoneName(spineInt);

	std::cout << spineParentName << " vector = x : " << pos.x << "; y : " << pos.y << "; z : " << pos.z << ";" << std::endl;

}