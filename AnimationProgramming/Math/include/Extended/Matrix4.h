#ifndef EXTENDED_MATRIX4_H
#define EXTENDED_MATRIX4_H

#include "BE.h"
#include "Math/Matrix4.h"

namespace BE
{
namespace Math
{
namespace Extended
{

struct Matrix4
{
    private:
        // Data members
        Mat4    base{};
        f32     det_{NAN};

        constexpr void update_det() noexcept;

    public:
        // Constructors
        constexpr Matrix4(const Math::Matrix4& base, const f32 det = NAN) noexcept;
        constexpr Matrix4(const f32 a11, const f32 a12,  const f32 a13,
                          const f32 a14, const f32 a21, const f32 a22,
                          const f32 a23, const f32 a24, const f32 a31,
                          const f32 a32, const f32 a33, const f32 a34,
                          const f32 a41, const f32 a42, const f32 a43,
                          const f32 a44, const f32 det = NAN) noexcept;

        // Static methods, pseudo-constructors
        static constexpr Matrix4 zero       () noexcept;
        static constexpr Matrix4 identity   () noexcept;

        // Methods
        Matrix4 cofactor  () const noexcept;
        Matrix4 transposed() const noexcept;
        Matrix4 adjugate  () const noexcept;
        f32     det       () noexcept;
        Matrix4 inversed  () noexcept;

        void        set_column (const u8 i, const Vec4& v) noexcept;
        Math::Vec4  get_column (const u8 i) const noexcept;

        // Operator overloads
        Matrix4&        operator*=  (const Matrix4& m)      noexcept;
        Matrix4&        operator/=  (const f32 k)           noexcept;
        Matrix4         operator*   (const Matrix4& mat)    const noexcept;
        Vec4            operator*   (const Math::Vec4& v)   const noexcept;
        Matrix4         operator/   (const f32 k)           const noexcept;
        f32             operator[]  (const u8 i)            const noexcept;

        #ifdef DEBUG
        friend std::ostream& operator<<(std::ostream& os, const Matrix4& m) noexcept;
        #endif
};

using Mat4 = Matrix4;

#include "Math/Extended/Matrix4.inl"

} // End of namespace Math

#endif