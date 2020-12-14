#ifndef EXTENDED_VECTOR3_H
#define EXTENDED_VECTOR3_H

#include "Math/Vector3.h"

namespace BE
{
namespace Math
{
namespace Extended
{

struct Vector3
{
    private:
        Math::Vector3   base{};
        f32             len2{NAN};
        f32             len {NAN};

        void    update_len2 () noexcept;
        void    update_len  () noexcept;

    public:
        // Constructors
        constexpr Vector3() = default;
        constexpr Vector3(const Math::Vec3& v,
                          const f32         length2 = NAN,
                          const f32         length  = NAN);
        constexpr Vector3(const f32 x, const f32 y, const f32 z);

        // Static methods (pseudo-constructors)
        static constexpr Vector3 zero   ()                          noexcept;
        static constexpr Vector3 left   ()                          noexcept;
        static constexpr Vector3 up     ()                          noexcept;
        static constexpr Vector3 forward()                          noexcept;

        // Methods
        f32         length2             ()                          noexcept;
        f32         length              ()                          noexcept;
        f32         dot                 (const Vector3& v)          const noexcept;
        Vector3     cross               (const Vector3& v)          const noexcept;
        bool        null                ()                          const noexcept;
        bool        orthogonal_to       (const Vector3& v)          const noexcept;
        bool        is_normalized       ()                          noexcept;
        bool        orthonormal_to      (const Vector3& v)          noexcept;
        bool        orthonormal_to      (Vector3& v)                noexcept;
        bool        colinear_to         (const Vector3& v)          const noexcept;
        bool        equal_to            (const Vector3& v,
                                         const f32 eps = FLT_EPSILON)   const noexcept;
        bool        not_equal_to        (const Vector3& v,
                                         const f32 eps = FLT_EPSILON)   const noexcept;
        void        normalize           ()                          noexcept;
        f32	        distance2_to        (const Vector3& v)          const noexcept;
        f32	        distance_to		    (const Vector3& v)          const noexcept;
        f32	        angle_with_unitary  (const Vector3& v)          noexcept;
        f32	        angle_with		    (const Vector3& v)          noexcept;
        f32	        angle_with		    (Vector3& v)                noexcept;
        f32	        triangle_area	    (const Vector3& v)          const noexcept;
        Vector3     normalized          ()                          noexcept;
        Vector3     projected_on_unitary(const Vector3& v)          const noexcept;
        Vector3     projected_on        (const Vector3& v)          const noexcept;
        Vector3     projected_on        (Vector3& v)                const noexcept;
        Vector3     rotated_around_unitary(const Vector3& v,
                                           const f32 angle)         const noexcept;
        Vector3     rotated_around      (const Vector3& v,
                                         const f32 angle)           const noexcept;
        Vector3     rotated_around      (Vector3& v,
                                         const f32 angle)           const noexcept;
        Vector3     lerp                (const Vector3& v,
                                         const f32 t)               const noexcept;
        
        constexpr Math::Vec3    xyz     ()                          const noexcept;
        constexpr f32           x       ()                          const noexcept;
        constexpr f32           y       ()                          const noexcept;
        constexpr f32           z       ()                          const noexcept;
        constexpr f32&          x       ()                          noexcept;
        constexpr f32&          y       ()                          noexcept;
        constexpr f32&          z       ()                          noexcept;

        // Operator overloads
        Vector3&	operator+=  (const Vector3& v)  noexcept;
        Vector3&	operator+=  (const Vector3&& v) noexcept;
        Vector3&	operator-=  (const Vector3& v)  noexcept;
        Vector3&	operator-=  (const Vector3&& v) noexcept;
        Vector3&	operator*=  (const Vector3& v)  noexcept;
        Vector3&	operator*=  (const Vector3&& v) noexcept;
        Vector3&	operator/=  (const Vector3& v)  noexcept;
        Vector3&	operator/=  (const Vector3&& v) noexcept;
        Vector3&    operator*=  (const f32 k)       noexcept;
        Vector3&    operator/=  (const f32 k)       noexcept;
        Vector3     operator+   (const Vector3& v)  const noexcept;
        Vector3     operator+   (const Vector3&& v) const noexcept;
        Vector3     operator-   (const Vector3& v)  const noexcept;
        Vector3     operator-   (const Vector3&& v) const noexcept;
        Vector3     operator-   ()                  const noexcept;
        Vector3	    operator*   (const Vector3& v)  const noexcept;
        Vector3	    operator*   (const Vector3&& v) const noexcept;
        Vector3	    operator/   (const Vector3& v)  const noexcept;
        Vector3	    operator/   (const Vector3&& v) const noexcept;
        Vector3	    operator*   (const f32 k)       const noexcept;
        Vector3	    operator/   (const f32 k)       const noexcept;
        operator    Math::Vector3()                 noexcept;

        #ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os, const Vector3& v) noexcept;
        #endif
};

using Vec3 = Vector3;
using vec3 = Vector3;

#include "Math/Extended/Vector3.inl"

} // End of namespace Extended
} // End of namespace Math
} // End of namespace BE

#endif 