#ifndef BONE_H
#define BONE_H

#include "BonePose.h"
#include "Matrix4.h"

struct Skeleton;

// invBindPose is the matrix which undoes the T-pose of this bone
struct Bone
{
    Math::Matrix4   invBindPos;
    BonePose        pose;
    unsigned char   parent; // index of the parent, in the bone array of the Skeleton

    Bone(int index, Skeleton& skeleton);
    Bone();
};

#endif