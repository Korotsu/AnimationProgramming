#include "AnimData.h"

#include "BonePose.h"
#include "Engine.h"
#include "Keyframe.h"
#include "Quaternion.h"
#include "Skeleton.h"

#include <stdlib.h>


AnimData::~AnimData() noexcept
{
    delete[] keyframes;
}

void AnimData::Init(const char* animName) noexcept
{
    count       = GetAnimKeyCount(animName);
    keyframes   = new Keyframe[count];

    const size_t boneCount{GetSkeletonBoneCount()};

    for (size_t i{0u}; i < count; ++i)
    {
        Keyframe& keyframe{keyframes[i]};
        keyframe.Init(boneCount);

        for (size_t j{0u}; j < boneCount; ++j)
        {
            Math::Quat& rot{keyframe.poses[j].rot};
            Math::Vec3& pos{keyframe.poses[j].trans};

            GetAnimLocalBoneTransform(animName, j, i, pos.x, pos.y, pos.z, rot.s, rot.v.x, rot.v.y, rot.v.z);
        }
    }
}


void AnimData::ApplyKeyframeTo(size_t keyframeIndex, Skeleton& skeleton) const noexcept
{
    skeleton.ApplyKeyframe(keyframes[keyframeIndex % count]);
}