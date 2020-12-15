/* =================== Methods =================== */
inline constexpr Vector4 Vector4::homogenized() const noexcept
{ return {xyz / w, 1.f}; }


inline constexpr void Vector4::homogenize() noexcept
{
    xyz /= w;
    w = 1.f;
}




/* =================== Operator overloads =================== */
inline constexpr Vector4 Vector4::operator*(const Vector4& v) const noexcept
{ return {xyz * v.xyz, w * v.w}; }


inline constexpr Vector4 Vector4::operator/(const Vector4& v) const noexcept
{ return {xyz / v.xyz, w / v.w}; }


inline constexpr Vector4 Vector4::operator*(const f32 k) const noexcept
{ return {xyz * k, w * k}; }


inline constexpr Vector4 Vector4::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};
    return {xyz * reciprocal, w * reciprocal};
}
