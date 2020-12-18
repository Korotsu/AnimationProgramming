#include "AnimData.h"

#include "BonePose.h"
#include "Engine.h"
#include "Keyframe.h"
#include "Quaternion.h"
#include "Skeleton.h"


AnimData::~AnimData()
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
        for (size_t j{0u}; i < boneCount; ++j)
        {
            Math::Quat& rot = keyframes[i].poses[j].rot;
            Math::Vec3& pos = keyframes[i].poses[j].trans;

            GetAnimLocalBoneTransform(animName, j, i, pos.x, pos.y, pos.z, rot.s, rot.v.x, rot.v.y, rot.v.z);
        }
    }
}


const BonePose& AnimData::GetKeyframeBoneTransform(size_t keyframeIndex, int boneIndex) const noexcept
{ return keyframes[keyframeIndex].poses[boneIndex]; }


void AnimData::ApplyKeyframeTo(size_t keyframeIndex, Skeleton& skeleton) const noexcept
{
    skeleton.ApplyKeyframe(keyframes[keyframeIndex % count]);
}