#include "BonePose.h"
#include "conversion.h"


Math::Matrix4 BonePose::toMatrix() const noexcept
{
    Math::Matrix4 ret{scale.x, .0f, .0f, .0f,
                      .0f, scale.y, .0f, .0f,
                      .0f, .0f, scale.z, .0f,
                      .0f, .0f, .0f, 1.f};

    ret *= Math::toMatrix4(rot);

    ret *= {1.f, .0f, .0f, trans.x,
            0.f, 1.f, .0f, trans.y,
            0.f, .0f, 1.f, trans.z,
            0.f, .0f, .0f, 1.f};

    //Math::Mat4 t = Math::Mat

    return ret;
}