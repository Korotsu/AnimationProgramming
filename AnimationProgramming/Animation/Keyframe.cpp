#include "Keyframe.h"
#include "BonePose.h"

Keyframe::~Keyframe() noexcept
{
    delete[] poses;
}


void Keyframe::Init(size_t boneCount) noexcept
{
    poses = new BonePose[boneCount];
}