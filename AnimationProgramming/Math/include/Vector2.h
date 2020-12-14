#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <cfloat>
#include "trigonometry.h"

#ifdef DEBUG
#include <iostream>
#endif


namespace Math
{

struct Vector2
{
    // Data members
    f32 x{.0f};
    f32 y{.0f};
    
    // Static methods (pseudo-constructors)
    static constexpr Vector2 zero   () noexcept;
    static constexpr Vector2 right  () noexcept;
    static constexpr Vector2 up     () noexcept;

    // Member methods
    constexpr f32       length2             ()                  const noexcept;
    f32                 length              ()                  const noexcept;
    constexpr f32       dot                 (const Vector2& v)  const noexcept;
    constexpr f32       cross               (const Vector2& v)  const noexcept;
    constexpr bool      null                ()                  const noexcept;
    constexpr bool      orthogonal_to       (const Vector2& v)  const noexcept;
    constexpr bool      is_normalized       ()                  const noexcept;
    constexpr bool      orthonormal_to      (const Vector2& v)  const noexcept;
    constexpr bool      colinear_to         (const Vector2& v)  const noexcept;
    bool                equal_to            (const Vector2& v,
                                             const f32 eps = FLT_EPSILON) const noexcept;
    bool                not_equal_to        (const Vector2& v,
                                             const f32 eps = FLT_EPSILON) const noexcept;
    void                normalize           ()                  noexcept;
    constexpr f32       distance2_to        (const Vector2& v)  const noexcept;
    f32                 distance_to         (const Vector2& v)  const noexcept;
    f32                 angle_with_unitary  (const Vector2& v)  const noexcept;
    f32                 angle_with          (const Vector2& v)  const noexcept;
    constexpr f32       triangle_area       (const Vector2& v)  const noexcept;
    Vector2             normalized          ()                  const noexcept;
    constexpr Vector2   projected_on_unitary(const Vector2& v)  const noexcept;
    constexpr Vector2   projected_on        (const Vector2& v)  const noexcept;
    Vector2             rotated             (const f32 angle)   const noexcept;
    constexpr Vector2   rotated_90          ()                  const noexcept;
    constexpr Vector2   lerp                (const Vector2& v, const f32 f32) const noexcept;

    // Operator overloads
    constexpr Vector2&  operator+=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator+=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator-=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator-=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator*=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator*=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator/=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator/=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator*=          (const f32 k)       noexcept;
    constexpr Vector2&  operator/=          (const f32 k)       noexcept;
    constexpr Vector2   operator+           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator+           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator-           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator-           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator*           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator*           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator/           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator/           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator-           ()                  const noexcept;
    constexpr Vector2   operator*           (const f32 k)       const noexcept;
    constexpr Vector2   operator/           (const f32 k)       const noexcept;

    #ifdef DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) noexcept;
    #endif
};

using Vec2 = Vector2;
using vec2 = Vector2;

#include "Vector2.inl"

} // End of namespace Math

#endif