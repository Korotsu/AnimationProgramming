#include "stdafx.h"

#include "Engine.h"
#include "Simulation.h"
#include "Skeleton.h"
#include "Bone.h"
#include "Transform.h"
#include "AnimData.h"

#include <chrono>

class CSimulation final : public ISimulation
{
	private:
		Skeleton	mainSkeleton;
		AnimData	walkAnim;
		size_t		animationProgress	{0u};

		const float								frameRate{1.f / 30.f};
		std::chrono::steady_clock::time_point	t1;

		virtual void Init() final
		{
			mainSkeleton.Init();
			walkAnim.Init("ThirdPersonWalk.anim");
		}


		virtual void Update(float frameTime) final
		{
			// Draw world referential gizmo
			DrawLine(0, 0, 0, 100, 0, 0, 1, 0, 0);
			DrawLine(0, 0, 0, 0, 100, 0, 0, 1, 0);
			DrawLine(0, 0, 0, 0, 0, 100, 0, 0, 1);

			const std::chrono::steady_clock::time_point t2{std::chrono::steady_clock::now()};
			const std::chrono::duration<float> duration{t2 - t1};
			if (duration.count() >= frameRate)
			{
				walkAnim.ApplyKeyframeTo(animationProgress++, mainSkeleton);

				// Gather all pose matrices and send them to the skinning shader
				mainSkeleton.GatherMatrixPalette();
				SetSkinningPose((float*)mainSkeleton.palette, mainSkeleton.size);

				t1 = t2;
			}

			mainSkeleton.Draw();
		}
};


int main()
{
	CSimulation simulation;
	Run(&simulation, 1400, 800);

	return 0;
}