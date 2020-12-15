#ifndef BONEPOSE_H
#define BONEPOSE_H

#include "Quaternion.h"

struct BonePose
{
    Math::Quaternion    rot;
    Math::Vector3       trans;
    Math::Vector3       scale;
};

#endif