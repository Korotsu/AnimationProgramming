#include "stdafx.h"

#include "Engine.h"
#include "Simulation.h"
#include "Skeleton.h"
#include "Bone.h"
#include "Transform.h"

#include <utility>
#include <ctime>

class CSimulation final : public ISimulation
{
	private:
		Skeleton mainSkeleton;

		virtual void Init() final
		{
			mainSkeleton.Init();

			//mainSkeleton.boneList[10].Move({.0f, -10.f, .0f}, mainSkeleton);


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
			mainSkeleton.ApplyAnimTransform("ThirdPersonWalk.anim", 1u);
		}


		virtual void Update(float frameTime) final
		{
			// X axis
			DrawLine(0, 0, 0, 100, 0, 0, 1, 0, 0);

			// Y axis
			DrawLine(0, 0, 0, 0, 100, 0, 0, 1, 0);

			// Z axis
			DrawLine(0, 0, 0, 0, 0, 100, 0, 0, 1);

			mainSkeleton.Draw();

			// Gather all pose matrices
			mainSkeleton.GatherMatrixPalette();

			SetSkinningPose((float*)mainSkeleton.palette, mainSkeleton.size);
		}
};


int main()
{
	CSimulation simulation;
	Run(&simulation, 1400, 800);

	return 0;
}