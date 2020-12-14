/* ======================== Private, internal ======================== */
inline constexpr void Vector2::update_len2() noexcept
{
    if (std::isnan(len2))
        len2 = base.length2();
}


inline constexpr void Vector2::update_len() noexcept
{
    if (std::isnan(len))
    {
        update_len2();
        len = sqrtf(len2);
    }
}




/* ======================== Constructors ======================== */
inline constexpr Vector2::Vector2(const Math::Vec2& v,
								  const f32			length2,
								  const f32			length)
	: base{v}, len2{length2}, len{length}
{}


inline constexpr Vector2::Vector2(const f32 x, const f32 y)
	: base{x, y}, len2{NAN}, len{NAN}
{}




/* =================== Static methods (pseudo-constructors) =================== */
inline constexpr Vector2 Vector2::zero() noexcept
{ return {Math::Vec2::zero(), .0f, .0f}; }


inline constexpr Vector2 Vector2::right() noexcept
{ return {Math::Vec2::right(), 1.f, 1.f}; }


inline constexpr Vector2 Vector2::up() noexcept
{ return {Math::Vec2::up(), 1.f, 1.f}; }




/* =================== Methods =================== */
inline f32 Vector2::length2() noexcept
{
    update_len2();
    return len2;
}


inline f32 Vector2::length() noexcept
{
    update_len();
    return len;
}


inline f32 Vector2::dot(const Vector2& v) const noexcept
{ return base.dot(v.base); }


inline f32 Vector2::cross(const Vector2& v) const noexcept
{ return base.cross(v.base); }


inline bool Vector2::null() const noexcept
{ return base.null(); }


inline bool Vector2::orthogonal_to(const Vector2& v) const noexcept
{ return base.orthogonal_to(v.base); }


inline bool Vector2::is_normalized() noexcept
{ return !(length2() - 1.f); }


inline bool Vector2::orthonormal_to(Vector2& v) noexcept
{ return !dot(v) && is_normalized() && v.is_normalized(); }


inline bool Vector2::orthonormal_to(const Vector2& v) noexcept
{ return base.orthonormal_to(v.base); }


inline bool Vector2::colinear_to(const Vector2& v) const noexcept
{ return base.colinear_to(v.base); }


inline bool Vector2::equal_to(const Vector2& v, const f32 eps) const noexcept
{ return base.equal_to(v.base, eps); }


inline bool Vector2::not_equal_to(const Vector2& v, const f32 eps) const noexcept
{ return base.not_equal_to(v.base, eps); }


inline void Vector2::normalize() noexcept
{
	update_len();
	
	base /= len;
	len2 = len = 1.f;
}


inline f32 Vector2::distance2_to(const Vector2& v) const noexcept
{ return base.distance2_to(v.base); }


inline f32 Vector2::distance_to(const Vector2& v) const noexcept
{ return base.distance_to(v.base); }


inline f32 Vector2::angle_with_unitary(const Vector2& v) noexcept
{ return angle_from_cos(dot(v) / length()); }


inline f32 Vector2::angle_with(const Vector2& v) noexcept
{ return angle_from_cos(dot(v) / sqrtf(length2() * v.base.length2())); }


inline f32 Vector2::angle_with(Vector2& v) noexcept
{ return angle_from_cos(dot(v) / sqrtf(length2() * v.length2())); }


inline f32 Vector2::triangle_area(const Vector2& v) const noexcept
{ return base.triangle_area(v.base); }


inline Vector2 Vector2::projected_on(const Vector2& v) const noexcept
{ return base.projected_on(v.base); }


inline Vector2 Vector2::projected_on(Vector2& v) const noexcept
{ return v * (dot(v) / v.length2()); }


inline Vector2 Vector2::normalized() noexcept
{
	update_len();
	return *this / len;
}


inline Vector2 Vector2::rotated(const f32 angle) const noexcept
{ return {base.rotated(angle), len2, len}; }


inline Vector2 Vector2::rotated_90() const noexcept
{ return {base.rotated_90(), len2, len}; }


inline Vector2 Vector2::lerp(const Vector2& v, const f32 t) const noexcept
{ return base.lerp(v.base, t); }


inline constexpr Math::Vector2 Vector2::xy() const noexcept
{ return base; }


inline constexpr f32 Vector2::x() const noexcept
{ return base.x; }


inline constexpr f32 Vector2::y() const noexcept
{ return base.y; }


inline constexpr f32& Vector2::x() noexcept
{
    len2 = len = NAN;
    return base.x;
}


inline constexpr f32& Vector2::y() noexcept
{
    len2 = len = NAN;
    return base.y;
}


inline Vector2& Vector2::operator+=(const Vector2& v) noexcept
{
	base += v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator+=(const Vector2&& v) noexcept
{
	base += v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator-=(const Vector2& v) noexcept
{
	base -= v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator-=(const Vector2&& v) noexcept
{
	base -= v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator*=(const Vector2& v) noexcept
{
	base *= v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator*=(const Vector2&& v) noexcept
{
	base *= v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator/=(const Vector2& v) noexcept
{
	base /= v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator/=(const Vector2&& v) noexcept
{
	base /= v.base;
	len2 = len = NAN;

	return *this;
}


inline Vector2& Vector2::operator*=(const f32 k) noexcept
{
	base	*= k;
	len2	*= k * k;
	len 	*= k;

	return *this;
}


inline Vector2& Vector2::operator/=(const f32 k) noexcept
{
	const f32	reciprocal{1.f / (k * k)},
				halfReciprocal{reciprocal * k};

	base	*= halfReciprocal;
	len2	*= reciprocal;
	len		*= halfReciprocal;

	return *this;
}


Vector2 Vector2::operator+(const Vector2& v) const noexcept
{ return base + v.base; }


Vector2 Vector2::operator+(const Vector2&& v) const noexcept
{ return base + v.base; }


Vector2 Vector2::operator-(const Vector2& v) const noexcept
{ return base - v.base; }


Vector2 Vector2::operator-(const Vector2&& v) const noexcept
{ return base - v.base; }


Vector2 Vector2::operator*(const Vector2& v) const noexcept
{ return base * v.base; }


Vector2 Vector2::operator*(const Vector2&& v) const noexcept
{ return base * v.base; }


Vector2 Vector2::operator/(const Vector2& v) const noexcept
{ return base / v.base; }


Vector2 Vector2::operator/(const Vector2&& v) const noexcept
{ return base / v.base; }


inline Vector2 Vector2::operator-() const noexcept
{ return {-base, len2, len}; }


inline Vector2 Vector2::operator*(const f32 k) const noexcept
{ return {base * k, len * k, len2 * k * k}; }


inline Vector2 Vector2::operator/(const f32 k) const noexcept
{
	const f32 reciprocal{1.f / (k * k)},
			  halfReciprocal{reciprocal * k};

	return {base * halfReciprocal, len2 * reciprocal, len * halfReciprocal};
}


inline Vector2::operator Math::Vector2() noexcept
{ return base; }


#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& os, const Vector2& v) noexcept
{ return os << v.base << ", len2 = " << v.len2 << ", len = " << v.len; }
#endif