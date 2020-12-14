/* ======================== Private, internal ======================== */
inline void Vector3::update_len2() noexcept
{
    if (std::isnan(len2))
        len2 = base.length2();
}


inline void Vector3::update_len() noexcept
{
    if (std::isnan(len))
    {
        update_len2();
        len = sqrtf(len2);
    }
}




/* ======================== Constructors ======================== */
inline constexpr Vector3::Vector3(const Math::Vec3& v,
                                  const f32         length2,
                                  const f32         length)
    : base{v}, len2{length2}, len{length}
{}


inline constexpr Vector3::Vector3(const f32 x, const f32 y, const f32 z)
    : base{x, y, z}, len2{NAN}, len{NAN}
{}




/* =================== Static methods (pseudo-constructors) =================== */
inline constexpr Vector3 Vector3::zero() noexcept
{ return {Math::Vec3::zero(), .0f, .0f}; }


inline constexpr Vector3 Vector3::left() noexcept
{ return {Math::Vec3::left(), 1.f, 1.f}; }


inline constexpr Vector3 Vector3::up() noexcept
{ return {Math::Vec3::up(), 1.f, 1.f}; }


inline constexpr Vector3 Vector3::forward() noexcept
{ return {Math::Vec3::forward(), 1.f, 1.f}; }




/* =================== Methods =================== */
inline f32 Vector3::length2() noexcept
{
    update_len2();

    return len2;
}


inline f32 Vector3::length() noexcept
{
    update_len();

    return len;
}


inline f32 Vector3::dot(const Vector3& v) const noexcept
{ return base.dot(v.base); }


inline Vector3 Vector3::cross(const Vector3& v) const noexcept
{ return base.cross(v.base); }


inline bool Vector3::null() const noexcept
{ return base.null(); }


inline bool Vector3::orthogonal_to(const Vector3& v) const noexcept
{ return base.orthogonal_to(v.base); }


inline bool Vector3::is_normalized() noexcept
{ return !(length2() - 1.f); }


inline bool Vector3::orthonormal_to(const Vector3& v) noexcept
{ return base.orthonormal_to(v.base); }


inline bool Vector3::orthonormal_to(Vector3& v) noexcept
{ return !dot(v) && is_normalized() && v.is_normalized(); }


inline bool Vector3::colinear_to(const Vector3& v) const noexcept
{ return base.colinear_to(v.base); }


inline bool Vector3::equal_to(const Vector3& v, const f32 eps) const noexcept
{ return base.equal_to(v.base, eps); }


inline bool Vector3::not_equal_to(const Vector3& v, const f32 eps) const noexcept
{ return base.not_equal_to(v.base, eps); }


inline void Vector3::normalize() noexcept
{
    update_len();
    base /= len;
    len2 = len = 1.f;
}


inline f32 Vector3::distance2_to(const Vector3& v) const noexcept
{ return base.distance2_to(v.base); }


inline f32 Vector3::distance_to(const Vector3& v) const noexcept
{ return base.distance_to(v.base); }


inline f32 Vector3::angle_with_unitary(const Vector3& v) noexcept
{ return angle_from_cos(dot(v) / length()); }


inline f32 Vector3::angle_with(const Vector3& v) noexcept
{ return angle_from_cos(dot(v) / sqrtf(length2() * v.base.length2())); }


inline f32 Vector3::angle_with(Vector3& v) noexcept
{ return angle_from_cos(dot(v) / sqrtf(length2() * v.length2())); }


inline f32 Vector3::triangle_area(const Vector3& v) const noexcept
{ return base.triangle_area(v.base); }


inline Vector3 Vector3::projected_on_unitary(const Vector3& v) const noexcept
{ return base.projected_on_unitary(v.base); }


inline Vector3 Vector3::projected_on(const Vector3& v) const noexcept
{ return base.projected_on(v.base); }


inline Vector3 Vector3::projected_on(Vector3& v) const noexcept
{ return v * (dot(v) / v.length2()); }


inline Vector3 Vector3::normalized() noexcept
{
    update_len();
	return *this / len;
}


// Rodriguez rotation around v, by angle radians
inline Vector3 Vector3::rotated_around_unitary(const Vector3& v, const f32 angle) const noexcept
{ return {base.rotated_around_unitary(v.base, angle), len2, len}; }


inline Vector3 Vector3::rotated_around(const Vector3& v, const f32 angle) const noexcept
{ return rotated_around_unitary(v.base.normalized(), angle); }


inline Vector3 Vector3::rotated_around(Vector3& v, const f32 angle) const noexcept
{ return rotated_around_unitary(v.normalized(), angle); }


inline Vector3 Vector3::lerp(const Vector3& v, const f32 t) const noexcept
{ return base.lerp(v.base, t); }


inline constexpr Math::Vector3 Vector3::xyz() const noexcept
{ return base; }


inline constexpr f32 Vector3::x() const noexcept
{ return base.x; }


inline constexpr f32 Vector3::y() const noexcept
{ return base.y; }


inline constexpr f32 Vector3::z() const noexcept
{ return base.z; }


inline constexpr f32& Vector3::x() noexcept
{
    len2 = len = NAN;
    return base.x;
}


inline constexpr f32& Vector3::y() noexcept
{
    len2 = len = NAN;
    return base.y;
}


inline constexpr f32& Vector3::z() noexcept
{
    len2 = len = NAN;
    return base.z;
}


inline Vector3& Vector3::operator+=(const Vector3& v) noexcept
{
    base = v.base;
    len2 = len = NAN;

	return *this;
}


inline Vector3& Vector3::operator+=(const Vector3&& v) noexcept
{
    base = v.base;
    len2 = len = NAN;

	return *this;
}


inline Vector3& Vector3::operator-=(const Vector3& v) noexcept
{
    base -= v.base;
    len2 = len = NAN;

	return *this;
}


inline Vector3& Vector3::operator-=(const Vector3&& v) noexcept
{
    base -= v.base;
    len2 = len = NAN;

	return *this;
}


inline Vector3& Vector3::operator*=(const Vector3& v) noexcept
{
    base *= v.base;
    len2 = len = NAN;

    return *this;
}


inline Vector3& Vector3::operator*=(const Vector3&& v) noexcept
{
    base *= v.base;
    len2 = len = NAN;

    return *this;
}


inline Vector3& Vector3::operator/=(const Vector3& v) noexcept
{
    base /= v.base;
    len2 = len = NAN;

    return *this;
}


inline Vector3& Vector3::operator/=(const Vector3&& v) noexcept
{
    base /= v.base;
    len2 = len = NAN;

    return *this;
}


inline Vector3& Vector3::operator*=(const f32 k) noexcept
{
    base    *= k;
    len2	*= k * k;
	len 	*= k;

    return *this;
}


// Floating point division takes significantly more clock cycles
// than multiplication
// See https://www.agner.org/optimize/optimizing_cpp.pdf, page 149
inline Vector3& Vector3::operator/=(const f32 k) noexcept
{
    const f32   reciprocal{1.f / (k * k)},
                halfReciprocal{reciprocal * k};

    base    *= halfReciprocal;
    len2    *= reciprocal;
    len     *= halfReciprocal;

    return *this;
}


inline Vector3 Vector3::operator+(const Vector3& v) const noexcept
{ return base + v.base; }


inline Vector3 Vector3::operator+(const Vector3&& v) const noexcept
{ return base + v.base; }


inline Vector3 Vector3::operator-(const Vector3& v)	const noexcept
{ return base - v.base; }


inline Vector3 Vector3::operator-(const Vector3&& v) const noexcept
{ return base - v.base; }


inline Vector3 Vector3::operator*(const Vector3& v) const noexcept
{ return base * v.base; }


inline Vector3 Vector3::operator*(const Vector3&& v) const noexcept
{ return base * v.base; }


inline Vector3 Vector3::operator/(const Vector3& v) const noexcept
{ return base / v.base; }


inline Vector3 Vector3::operator/(const Vector3&& v) const noexcept
{ return base / v.base; }


inline Vector3 Vector3::operator-() const noexcept
{ return {-base, len2, len}; }


inline Vector3 Vector3::operator*(const f32 k) const noexcept
{ return {base * k, len2 * k * k, len * k}; }


inline Vector3 Vector3::operator/(const f32 k) const noexcept
{
    const f32 reciprocal    {1.f / (k * k)},
              halfReciprocal{reciprocal * k};

    return {base * halfReciprocal, len2 * reciprocal, len * halfReciprocal};
}


inline Vector3::operator Math::Vector3() noexcept
{ return base; }


#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& os, const Vector3& v) noexcept
{ return os << v.base << ", len2 = " << v.len2 << ", len = " << v.len; }
#endif