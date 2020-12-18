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
			mainSkeleton.ApplyAnimTransform("ThirdPersonWalk.anim", 0u);
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