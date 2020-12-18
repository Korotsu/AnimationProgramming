#ifndef KEYFRAME_H
#define KEYFRAME_H

struct BonePose;

struct Keyframe
{
    BonePose* poses{nullptr};

    ~Keyframe() noexcept;

    void Init(size_t boneCount) noexcept;
};

#endif