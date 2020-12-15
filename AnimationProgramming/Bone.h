#ifndef BONE_H
#define BONE_H

#include "Matrix4.h"
#include "BonePose.h"

struct Bone
{
    Math::Matrix4   invBindPos;
    BonePose        localPose;
    BonePose        globalPose;
    Bone*           parent;
};

#endif

// Du coup j'envois ça sur le git