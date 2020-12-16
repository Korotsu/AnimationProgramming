#include "Skeleton.h"
#include "Bone.h"
#include "Engine.h"

Skeleton::Skeleton(size_t size) : boneList{new Bone[size]}
{
	for (size_t i = 0; i < size; i++)
	{
		boneList[i] = Bone(i, *this);
	}
}

Skeleton::~Skeleton()
{
	delete[] boneList;
}

void Skeleton::Draw()
{
	for (size_t i = 1; i < GetSkeletonBoneCount(); i++)
	{
		DrawLine(boneList[i].pose.trans.x, boneList[i].pose.trans.y, boneList[i].pose.trans.z, boneList[boneList[i].parent].pose.trans.x, boneList[boneList[i].parent].pose.trans.y, boneList[boneList[i].parent].pose.trans.z, 1, 0, 0);
	}
}