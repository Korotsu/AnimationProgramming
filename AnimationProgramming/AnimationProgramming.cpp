#include "stdafx.h"

#include "Engine.h"
#include "Simulation.h"
#include "Skeleton.h"

class CSimulation final : public ISimulation
{
	virtual void Init() final
	{
		/*const size_t boneCount		= GetSkeletonBoneCount();
		int spine01					= GetSkeletonBoneIndex("spine_01");	// Bone parent
		int spineParent				= GetSkeletonBoneParentIndex(spine01);
		const char* spineParentName = GetSkeletonBoneName(spineParent);

		float posX, posY, posZ, quatW, quatX, quatY, quatZ;
		const size_t keyCount = GetAnimKeyCount("ThirdPersonWalk.anim");
		GetAnimLocalBoneTransform("ThirdPersonWalk.anim", spineParent, keyCount / 2, posX, posY, posZ, quatW, quatX, quatY, quatZ);

		for (size_t i{0u}; i < boneCount; ++i)
		{
			printf("Bone #%d: %s\n", i, GetSkeletonBoneName(i));
		}
		

		printf("Spine parent bone : %s\n", spineParentName);
		printf("Anim key count : %ld\n", keyCount);
		printf("Anim key : pos(%.2f,%.2f,%.2f) rotation quat(%.10f,%.10f,%.10f,%.10f)\n", posX, posY, posZ, quatW, quatX, quatY, quatZ);*/

		Skeleton::mainSkeleton = Skeleton(GetSkeletonBoneCount());
	}

	virtual void Update(float frameTime) final
	{
		/*// X axis
		DrawLine(0, 0, 0, 100, 0, 0, 1, 0, 0);

		// Y axis
		DrawLine(0, 0, 0, 0, 100, 0, 0, 1, 0);

		// Z axis
		DrawLine(0, 0, 0, 0, 0, 100, 0, 0, 1);*/

		Skeleton::mainSkeleton.Draw();
	}
};


int main()
{
	CSimulation simulation;
	Run(&simulation, 1400, 800);

	return 0;
}