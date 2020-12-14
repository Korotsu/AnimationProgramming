#ifndef EXTENDED_VECTOR2_H
#define EXTENDED_VECTOR2_H

#include "Math/Vector2.h"

namespace BE
{
namespace Math
{
namespace Extended
{

class Vector2
{
    private:
        // Data members
        Math::Vec2  base{};
        f32         len2{NAN};
        f32         len {NAN};

        // Private methods
        constexpr void  update_len2 ()  noexcept;
        constexpr void  update_len  ()  noexcept;
    
    public:
        // Constructor
        constexpr Vector2() = default;
        constexpr Vector2(const Math::Vec2& v,
                          const f32         length2 = NAN,
                          const f32         length  = NAN);
        constexpr Vector2(const f32 x, const f32 y);

        // Static methods (pseudo-constructors)
        static constexpr Vector2 zero   () noexcept;
        static constexpr Vector2 right  () noexcept;
        static constexpr Vector2 up     () noexcept;

        // Member methods
        f32         length2             ()                  noexcept;
        f32         length              ()                  noexcept;
        f32         dot                 (const Vector2& v)  const noexcept;
        f32         cross               (const Vector2& v)  const noexcept;
        bool        null                ()                  const noexcept;
        bool        orthogonal_to       (const Vector2& v)  const noexcept;
        bool        is_normalized       ()                  noexcept;
        bool        orthonormal_to      (const Vector2& v)  noexcept;
        bool        orthonormal_to      (Vector2& v)        noexcept;
        bool        colinear_to         (const Vector2& v)  const noexcept;
        bool        equal_to            (const Vector2& v,
                                         const f32 eps = FLT_EPSILON) const noexcept;
        bool        not_equal_to        (const Vector2& v,
                                         const f32 eps = FLT_EPSILON) const noexcept;
        void        normalize           ()                  noexcept;
        f32         distance2_to        (const Vector2& v)  const noexcept;
        f32         distance_to         (const Vector2& v)  const noexcept;
        f32         angle_with_unitary  (const Vector2& v)  noexcept;
        f32         angle_with          (const Vector2& v)  noexcept;
        f32         angle_with          (Vector2& v)        noexcept;
        f32         triangle_area       (const Vector2& v)  const noexcept;
        Vector2     normalized          ()                  noexcept;
        Vector2     projected_on_unitary(const Vector2& v)  const noexcept;
        Vector2     projected_on        (const Vector2& v)  const noexcept;
        Vector2     projected_on        (Vector2& v)        const noexcept;
        Vector2     rotated             (const f32 angle)   const noexcept;
        Vector2     rotated_90          ()                  const noexcept;
        Vector2     lerp                (const Vector2& v,
                                         const f32 t)       const noexcept;
                                         
        constexpr Math::Vec2    xy      ()                  const noexcept;
        constexpr f32           x       ()                  const noexcept;
        constexpr f32           y       ()                  const noexcept;
        constexpr f32&          x       ()                  noexcept;
        constexpr f32&          y       ()                  noexcept;

        // Operator overloads
        Vector2&    operator+=  (const Vector2& v)  noexcept;
        Vector2&    operator+=  (const Vector2&& v) noexcept;
        Vector2&    operator-=  (const Vector2& v)  noexcept;
        Vector2&    operator-=  (const Vector2&& v) noexcept;
        Vector2&    operator*=  (const Vector2& v)  noexcept;
        Vector2&    operator*=  (const Vector2&& v) noexcept;
        Vector2&    operator/=  (const Vector2& v)  noexcept;
        Vector2&    operator/=  (const Vector2&& v) noexcept;
        Vector2&    operator*=  (const f32 k)       noexcept;
        Vector2&    operator/=  (const f32 k)       noexcept;
        Vector2     operator+   (const Vector2& v)  const noexcept;
        Vector2     operator+   (const Vector2&& v) const noexcept;
        Vector2     operator-   (const Vector2& v)  const noexcept;
        Vector2     operator-   (const Vector2&& v) const noexcept;
        Vector2     operator*   (const Vector2& v)  const noexcept;
        Vector2     operator*   (const Vector2&& v) const noexcept;
        Vector2     operator/   (const Vector2& v)  const noexcept;
        Vector2     operator/   (const Vector2&& v) const noexcept;
        Vector2     operator-   ()                  const noexcept;
        Vector2     operator*   (const f32 k)       const noexcept;
        Vector2     operator/   (const f32 k)       const noexcept;
        operator    Math::Vector2()                 noexcept;

        #ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os, const Vector2& v) noexcept;
        #endif
};

using Vec2 = Vector2;

#include "Math/Extended/Vector2.inl"

} // End of namespace Extended
} // End of namespace Math
} // End of namespace BE
#endif