#include "BonePose.h"

Math::Matrix4 BonePose::toMatrix() const noexcept
{
    Math::Matrix4 ret;

    ret.coef[0]     = scale.x;
    ret.coef[5]     = scale.y;
    ret.coef[10]    = scale.z;

    ret *= rot; // Je retrouve pas ma méthode de conversion en matrice :' )
}