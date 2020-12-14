#ifndef VECTOR4_H
#define VECTOR4_H

#include "Vector3.h"

namespace Math
{

struct Vector4
{
    // Data members
    Vec3    xyz {};
    f32     w   {1.f};

    // Methods
    constexpr Vector4 homogenized ()  const noexcept;
    constexpr void    homogenize  ()  noexcept;

    constexpr Vector4 operator*  (const Vector4& v) const noexcept;
    constexpr Vector4 operator/  (const Vector4& v) const noexcept;
    constexpr Vector4 operator*  (const f32 k) const noexcept;
    constexpr Vector4 operator/  (const f32 k) const noexcept;
};

using Vec4 = Vector4;

#include "Vector4.inl"

} // End of namespace Math

#endif