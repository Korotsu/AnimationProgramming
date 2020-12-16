#ifndef BONEPOSE_H
#define BONEPOSE_H

#include "Quaternion.h"
#include "Matrix4.h"

struct BonePose
{
    Math::Quaternion    rot     {};
    Math::Vector3       trans   {};
    Math::Vector3       scale   {1.f, 1.f, 1.f};

    Math::Matrix4 toMatrix() const noexcept;
};

#endif