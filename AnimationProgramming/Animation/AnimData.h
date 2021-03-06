#ifndef ANIMDATA_H
#define ANIMDATA_H

struct Keyframe;
struct Skeleton;
struct BonePose;

struct AnimData
{
    size_t      count       {0u};
    Keyframe*   keyframes   {nullptr};

    ~AnimData() noexcept;

    void Init(const char* animName) noexcept;
    void ApplyKeyframeTo(size_t keyframeIndex, Skeleton& skeleton) const noexcept;
};

#endif