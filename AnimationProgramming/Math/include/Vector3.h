#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <cfloat>
#include "trigonometry.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace Math
{

struct Vector3
{
    // Data members
    f32 x{.0f};
    f32 y{.0f};
    f32 z{.0f};

    // Static methods (pseudo-constructors)
    static constexpr Vector3 zero           ()                              noexcept;
    static constexpr Vector3 one            ()                              noexcept;
    static constexpr Vector3 left           ()                              noexcept;
    static constexpr Vector3 up             ()                              noexcept;
    static constexpr Vector3 forward        ()                              noexcept;

    // Member methods
    constexpr f32       length2             ()                              const noexcept;
    f32                 length              ()                              const noexcept;
    constexpr f32       dot                 (const Vector3& v)              const noexcept;
    constexpr Vector3   cross               (const Vector3& v)              const noexcept;
    constexpr bool      null                ()                              const noexcept;
    constexpr bool      orthogonal_to       (const Vector3& v)              const noexcept;
    constexpr bool      is_normalized       ()                              const noexcept;
    constexpr  bool     orthonormal_to      (const Vector3& v)              const noexcept;
    constexpr  bool     colinear_to         (const Vector3& v)              const noexcept;
    bool                equal_to            (const Vector3& v,
                                             const f32 eps = FLT_EPSILON)   const noexcept;
    bool                not_equal_to        (const Vector3& v,
                                             const f32 eps = FLT_EPSILON)   const noexcept;
    void                normalize           ()                              noexcept;
    constexpr f32       distance2_to        (const Vector3& v)              const noexcept;
    f32     	        distance_to		    (const Vector3& v)              const noexcept;
    f32     	        angle_with_unitary  (const Vector3& v)              const noexcept;
    f32                 angle_with		    (const Vector3& v)              const noexcept;
    f32                 triangle_area	    (const Vector3& v)              const noexcept;
    Vector3             normalized          ()                              const noexcept;
    constexpr Vector3   projected_on_unitary(const Vector3& v)              const noexcept;
    constexpr Vector3   projected_on        (const Vector3& v)              const noexcept;
    Vector3             rotated_around_unitary(const Vector3& v,
                                               const f32 angle)             const noexcept;
    Vector3             rotated_around      (const Vector3& v,
                                             const f32 angle)               const noexcept;
    constexpr Vector3   lerp                (const Vector3& v,
                                             const f32 t)                   const noexcept;

    // Operator overloads
    constexpr Vector3&	operator+=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator+=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator-=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator-=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator*=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator*=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator/=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator/=          (const Vector3&& v)             noexcept;
    constexpr Vector3&  operator*=          (const f32 k)                   noexcept;
    constexpr Vector3&  operator/=          (const f32 k)                   noexcept;
    constexpr Vector3   operator+           (const Vector3& v)              const noexcept;
    constexpr Vector3   operator+           (const Vector3&& v)             const noexcept;
    constexpr Vector3   operator-           (const Vector3& v)              const noexcept;
    constexpr Vector3   operator-           (const Vector3&& v)             const noexcept;
    constexpr Vector3	operator*           (const Vector3& v)              const noexcept;
    constexpr Vector3	operator*           (const Vector3&& v)             const noexcept;
    constexpr Vector3	operator/           (const Vector3& v)              const noexcept;
    constexpr Vector3	operator/           (const Vector3&& v)             const noexcept;
    constexpr Vector3   operator-           ()                              const noexcept;
    constexpr Vector3	operator*           (const f32 k)                   const noexcept;
    constexpr Vector3	operator/           (const f32 k)                   const noexcept;

    #ifdef DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v) noexcept;
    #endif
};

using Vec3 = Vector3;
using vec3 = Vector3;

#include "Vector3.inl"

} // End of namespace Math

#endif 