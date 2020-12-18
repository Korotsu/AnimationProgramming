#include "stdafx.h"

#include "Engine.h"
#include "Simulation.h"
#include "Skeleton.h"
#include "Bone.h"
#include "Transform.h"
#include "AnimData.h"

#include <utility>
#include <mutex>

class CSimulation final : public ISimulation
{
	private:
		Skeleton	mainSkeleton;
		AnimData	walkAnim;
		size_t		animationProgress{0u};

		virtual void Init() final
		{
			mainSkeleton.Init();
			walkAnim.Init("ThirdPersonWalk.anim");
		}


		virtual void Update(float frameTime) final
		{
			// X axis
			DrawLine(0, 0, 0, 100, 0, 0, 1, 0, 0);

			// Y axis
			DrawLine(0, 0, 0, 0, 100, 0, 0, 1, 0);

			// Z axis
			DrawLine(0, 0, 0, 0, 0, 100, 0, 0, 1);

			walkAnim.ApplyKeyframeTo(animationProgress++, mainSkeleton);

			mainSkeleton.Draw();

			// Gather all pose matrices
			mainSkeleton.GatherMatrixPalette();

			SetSkinningPose((float*)mainSkeleton.palette, mainSkeleton.size);
		}
};


int main()
{
	std::mutex mutex;
	const std::lock_guard<std::mutex> lock{mutex};

	CSimulation simulation;
	Run(&simulation, 1400, 800);

	return 0;
}