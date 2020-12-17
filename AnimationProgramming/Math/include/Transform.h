#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "types.h"
#include "Matrix4.h"
#include "Vector3.h"
#include <cmath>

namespace Math
{

struct Transform
{
    //Mat4 mat;

    static constexpr Mat4   translation (const Vec3& v)     noexcept;
    static Mat4             rotation_x  (const f32 angle)   noexcept;
    static Mat4             rotation_y  (const f32 angle)   noexcept;
    static Mat4             rotation_z  (const f32 angle)   noexcept;
    static Mat4             rotation    (const Vec3& v)     noexcept;
    static constexpr Mat4   scaling     (const Vec3& v)     noexcept;
    static Mat4             TRS         (const Vec3& t,
                                         const Vec3& r,
                                         const Vec3& s)     noexcept;
    static constexpr Vec3   right       (const Mat4& m)     noexcept;
    static constexpr Vec3   up          (const Mat4& m)     noexcept;
    static constexpr Vec3   backward    (const Mat4& m)     noexcept;
    static constexpr Vec3   translation (const Mat4& m)     noexcept;
};

#include "Transform.inl"

} // End of namespace Math

#endif