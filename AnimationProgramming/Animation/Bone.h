#ifndef BONE_H
#define BONE_H

#include "BonePose.h"
#include "Matrix4.h"

struct Skeleton;

// invBindPose is the matrix which undoes the T-pose of this bone
struct Bone
{
    Math::Matrix4   invBindPose {};
    BonePose        pose        {};
    int             parentIndex {0};

    Bone() = default;
    Bone(Bone&& other) = default;
    Bone(int index, Skeleton& skeleton);

    Bone& operator=(Bone&& other) = default;
};

#endif