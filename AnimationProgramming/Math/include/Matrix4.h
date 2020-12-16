#ifndef MATRIX4_H
#define MATRIX4_H

#include "Quaternion.h"
#include "types.h"
#include "Vector4.h"

//#ifdef DEBUG
#include <iomanip>
#include <iostream>
//#endif

namespace Math
{

#define MAT4_COL 4u
#define MAT4_SIZE 16u

struct Matrix4
{
    // Data members, aligned by 16 to enable auto-vectorization
    alignas(16) f32 coef[MAT4_SIZE];

    // Static methods, pseudo-constructors
    static constexpr Matrix4 zero       ()                  noexcept;
    static constexpr Matrix4 identity   ()                  noexcept;

    // Methods
    Matrix4             cofactor        ()                  const noexcept;
    constexpr Matrix4   transposed      ()                  const noexcept;
    constexpr Matrix4   adjugate        ()                  const noexcept;
    constexpr f32       det             ()                  const noexcept;
    Matrix4             inversed        ()                  const noexcept;
    constexpr f32       trace           ()                  const noexcept;

    // Operator overloads
    constexpr Matrix4&  operator*=      (const Matrix4& m)  noexcept;
    constexpr Matrix4&  operator/=      (const f32 k)       noexcept;
    Matrix4             operator*       (const Matrix4& m)  const noexcept;
    constexpr Vec4      operator*       (const Vec4& v)     const noexcept;
    Matrix4             operator/       (const f32 k)       const noexcept;
    constexpr f32       operator[]      (const u8 i)        const noexcept;
    constexpr f32       operator()      (const u8 i, const u8 j) const noexcept;

    //#ifdef DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Matrix4& m) noexcept;
    //#endif
};

using Mat4 = Matrix4;
using mat4 = Matrix4;

#include "Matrix4.inl"

} // End of namespace Math

#endif