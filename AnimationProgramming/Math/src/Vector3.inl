/* =================== Static methods (pseudo-constructors) =================== */
inline constexpr Vector3 Vector3::zero() noexcept
{ return {.0f, .0f, .0f}; }


inline constexpr Vector3 Vector3::one() noexcept
{ return {1.f, 1.f, 1.f}; }


inline constexpr Vector3 Vector3::left() noexcept
{ return {1.f, .0f, .0f}; }


inline constexpr Vector3 Vector3::up() noexcept
{ return {.0f, 1.f, .0f}; }


inline constexpr Vector3 Vector3::forward() noexcept
{ return {.0f, .0f, 1.f}; }




/* =================== Methods =================== */
inline constexpr f32 Vector3::length2() const noexcept
{ return (x * x) + (y * y) + (z * z); }


inline f32 Vector3::length() const noexcept
{ return sqrtf(length2()); }


inline constexpr f32 Vector3::dot(const Vector3& v) const noexcept
{ return (x * v.x) + (y * v.y) + (z * v.z); }


inline constexpr Vector3 Vector3::cross(const Vector3& v) const noexcept
{
    return {(v.z * y) - (z * v.y),
            (v.x * z) - (x * v.z),
            (v.y * x) - (y * v.x)};
}


inline constexpr bool Vector3::null() const noexcept
{ return !x && !y && !z; }


inline constexpr bool Vector3::orthogonal_to(const Vector3& v) const noexcept
{ return !dot(v); }


inline constexpr bool Vector3::is_normalized() const noexcept
{ return !(length2() - 1.f); }


inline constexpr bool Vector3::orthonormal_to(const Vector3& v) const noexcept
{ return !dot(v) && is_normalized() && v.is_normalized(); }


inline constexpr bool Vector3::colinear_to(const Vector3& v) const noexcept
{ return cross(v).null(); }


inline bool Vector3::equal_to(const Vector3& v, const f32 eps) const noexcept
{ return fabs(x - v.x) <= eps && fabs(y - v.y) <= eps && fabs(z - v.z) <= eps; }


inline bool Vector3::not_equal_to(const Vector3& v, const f32 eps) const noexcept
{ return fabs(x - v.x) > eps || fabs(y - v.y) > eps || fabs(z - v.z) > eps; }



inline void Vector3::normalize() noexcept
{
    const f32 reciprocal{1.f / length()};

    x *= reciprocal;
    y *= reciprocal;
    z *= reciprocal;
}


inline constexpr f32 Vector3::distance2_to(const Vector3& v) const noexcept
{ return (*this - v).length2(); }


inline f32 Vector3::distance_to(const Vector3& v) const noexcept
{ return (*this - v).length(); }


inline f32 Vector3::angle_with_unitary(const Vector3& v) const noexcept
{ return angle_from_cos(dot(v) / length()); }


inline f32 Vector3::angle_with(const Vector3& v) const noexcept
{ return angle_from_cos(dot(v) / sqrtf(length2() * v.length2())); }


inline f32 Vector3::triangle_area(const Vector3& v) const noexcept
{ return cross(v).length() * .5f; }


inline constexpr Vector3 Vector3::projected_on_unitary(const Vector3& v) const noexcept
{ return v * dot(v); }


inline constexpr Vector3 Vector3::projected_on(const Vector3& v) const noexcept
{ return v * (dot(v) / v.length2()); }



inline Vector3 Vector3::normalized() const noexcept
{
    const f32 reciprocal{1.f / length()};

    return {x * reciprocal, y * reciprocal, z * reciprocal};
}


// Rodriguez rotation around v, by angle radians
inline Vector3 Vector3::rotated_around_unitary(const Vector3& v, const f32 angle) const noexcept
{
	const Vector3   cp{v.cross(*this)};
	const f32	    cosAngle{cosf(angle)}, dp{dot(v)};

    return (*this * cosAngle) + (cp * sinf(angle)) + v * (dp * (1.f - cosAngle));
}


inline Vector3 Vector3::rotated_around(const Vector3& v, const f32 angle) const noexcept
{ return rotated_around_unitary(v.normalized(), angle); }


inline constexpr Vector3 Vector3::lerp(const Vector3& v, const f32 t) const noexcept
{
    const f32 tmp{1.f - t};

    return {(x * tmp) + (v.x * t), (y * tmp) + (v.y * t), (z * tmp) + (v.z * t)};
}



inline constexpr Vector3& Vector3::operator+=(const Vector3& v) noexcept
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator+=(const Vector3&& v) noexcept
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator-=(const Vector3& v) noexcept
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator-=(const Vector3&& v) noexcept
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator*=(const Vector3& v) noexcept
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator*=(const Vector3&& v) noexcept
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator/=(const Vector3& v) noexcept
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator/=(const Vector3&& v) noexcept
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator*=(const f32 k) noexcept
{
    x *= k;
    y *= k;
    z *= k;

    return *this;
}


inline constexpr Vector3& Vector3::operator/=(const f32 k) noexcept
{
    const f32 reciprocal{1.f / k};
    
    x *= reciprocal;
    y *= reciprocal;
    z *= reciprocal;

    return *this;
}


inline constexpr Vector3 Vector3::operator+(const Vector3& v) const noexcept
{ return {x + v.x, y + v.y, z + v.z}; }


inline constexpr Vector3 Vector3::operator+(const Vector3&& v) const noexcept
{ return {x + v.x, y + v.y, z + v.z}; }


inline constexpr Vector3 Vector3::operator-(const Vector3& v)	const noexcept
{ return {x - v.x, y - v.y, z - v.z}; }


inline constexpr Vector3 Vector3::operator-(const Vector3&& v) const noexcept
{ return {x - v.x, y - v.y, z - v.z}; }


inline constexpr Vector3 Vector3::operator-() const noexcept
{ return {-x, -y, -z}; }


inline constexpr Vector3 Vector3::operator*(const Vector3& v) const noexcept
{ return {x * v.x, y * v.y, z * v.z}; }


inline constexpr Vector3 Vector3::operator*(const Vector3&& v) const noexcept
{ return {x * v.x, y * v.y, z * v.z}; }


inline constexpr Vector3 Vector3::operator/(const Vector3& v) const noexcept
{ return {x / v.x, y / v.y, z / v.z}; }


inline constexpr Vector3 Vector3::operator/(const Vector3&& v) const noexcept
{ return {x / v.x, y / v.y, z / v.z}; }


inline constexpr Vector3 Vector3::operator*(const f32 k) const noexcept
{ return {x * k, y * k, z * k}; }


inline constexpr Vector3 Vector3::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};

    return {x * reciprocal, y * reciprocal, z * reciprocal};
}


#ifdef DEBUG
inline constexpr std::ostream& operator<<(std::ostream& os, const Vector3& v) noexcept
{ return os << '[' << v.x << "; " << v.y << "; " << v.z << ']'; }
#endif