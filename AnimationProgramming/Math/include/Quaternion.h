#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h> // M_PI is needed
#include "Vector3.h"
#include "types.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Math
{

struct Matrix3;

struct Quaternion
{
    // Data members
    Vec3    v{};
    f32     s{.0f};

    // Constructors
    Quaternion(const f32 angle, const Vec3& axis) noexcept;
    Quaternion(const Matrix3& m) noexcept;
    constexpr Quaternion(const Vec3& v = {}, const f32 s = .0f) noexcept;

    static constexpr Quaternion identity    ()                                      noexcept;

    constexpr f32               length2     ()                                      const noexcept;
    f32                         length      ()                                      const noexcept;
    constexpr f32               dot         (const Quaternion& q)                   const noexcept;
    Quaternion                  normalized  ()                                      const noexcept;
    void                        normalize   ()                                      noexcept;
    constexpr Quaternion        inversed    ()                                      const noexcept;
    Quaternion                  slerp       (const Quaternion& target, const f32 t) const noexcept;
    Quaternion                  nlerp       (const Quaternion& target, const f32 t) const noexcept;

    // Getters, optional, only for comfort
    constexpr f32               x           ()                                      const noexcept;
    constexpr f32               y           ()                                      const noexcept;
    constexpr f32               z           ()                                      const noexcept;
    constexpr f32               w           ()                                      const noexcept;

    // Operator overloads
    constexpr Quaternion        operator+   (const Quaternion& q)                   const noexcept;
    constexpr Quaternion        operator-   (const Quaternion& q)                   const noexcept;
    constexpr Quaternion        operator-   ()                                      const noexcept;
    constexpr Quaternion        operator*   (const Quaternion& q)                   const noexcept;
    constexpr Vec3              operator*   (const Vec3& v)                         const noexcept;
    constexpr Quaternion        operator*   (const f32 k)                           const noexcept;
    constexpr Quaternion        operator/   (const f32 k)                           const noexcept;
    constexpr f32               operator[]  (const u8 k)                            const noexcept;
    constexpr f32&              operator[]  (const u8 k)                            noexcept;

    #ifdef DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Quaternion& q) noexcept;
    #endif
};

using Quat = Quaternion;
using quat = Quaternion;

#include "Quaternion.inl"

} // End of namespace Math

#endif