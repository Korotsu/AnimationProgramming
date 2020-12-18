#include "stdafx.h"

#include "Engine.h"
#include "Simulation.h"
#include "Skeleton.h"
#include "Bone.h"
#include "Transform.h"
#include "AnimData.h"

#include <utility>

class CSimulation final : public ISimulation
{
	private:
		Skeleton	mainSkeleton;
		AnimData	walkAnim; /* Uncomment to test raw walk animation */
		size_t		animationProgress{0u};


		virtual void Init() final
		{
			mainSkeleton.Init();
			walkAnim.Init("ThirdPersonWalk.anim"); /* Uncomment to test raw walk animation */
		}


		virtual void Update(float frameTime) final
		{
			// Draw world referential gizmo
			DrawLine(0, 0, 0, 100, 0, 0, 1, 0, 0);
			DrawLine(0, 0, 0, 0, 100, 0, 0, 1, 0);
			DrawLine(0, 0, 0, 0, 0, 100, 0, 0, 1);

			walkAnim.ApplyKeyframeTo(animationProgress++, mainSkeleton); /* Uncomment to test raw walk animation */

			mainSkeleton.Draw();

			// Gather all pose matrices and send them to the skinning shader
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