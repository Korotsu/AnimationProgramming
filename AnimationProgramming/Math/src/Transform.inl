/* =================== Static methods =================== */
inline constexpr Mat4 Transform::translation(const Vec3& v) noexcept
{
    return
    {
        1.f, .0f, .0f, .0f,
        .0f, 1.f, .0f, .0f,
        .0f, .0f, 1.f, .0f,
        v.x, v.y, v.z, 1.f
    };
}


inline Mat4 Transform::rotation_x(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};
    return
    {
        1.f,    .0f,        .0f,       .0f,
        .0f,    cosAngle,   sinAngle,  .0f,
        .0f,    -sinAngle,  cosAngle,  .0f,
        .0f,    .0f,        .0f,       1.f
    };
}


inline Mat4 Transform::rotation_y(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    return
    {
        cosAngle,   .0f,    -sinAngle,  .0f,
        .0f,        1.f,    .0f,        .0f,
        sinAngle,   .0f,    cosAngle,   .0f,
        .0f,        .0f,    .0f,        1.f
    };
}


inline Mat4 Transform::rotation_z(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    return
    {
        cosAngle,   sinAngle,   .0f,    .0f,
        -sinAngle,  cosAngle,   .0f,    .0f,
        .0f,        .0f,        1.f,    .0f,
        .0f,        .0f,        .0f,    1.f
    };
}


inline Mat4 Transform::rotation(const Vec3& v) noexcept
{ return rotation_y(v.y) * rotation_x(v.x) * rotation_z(v.z); }


inline constexpr Mat4 Transform::scaling(const Vec3& v) noexcept
{
    return
    {
        v.x, .0f, .0f, .0f,
        .0f, v.y, .0f, .0f,
        .0f, .0f, v.z, .0f,
        .0f, .0f, .0f, 1.f
    };
}


inline Mat4 Transform::TRS(const Vec3& t, const Vec3& r, const Vec3& s) noexcept
{ return translation(t) * rotation(r) * scaling(s); }


inline constexpr Vec3 Transform::right(const Mat4& m) noexcept
{ return {m.coef[0], m.coef[1], m.coef[2]}; }


inline constexpr Vec3 Transform::up(const Mat4& m) noexcept
{ return {m.coef[4], m.coef[5], m.coef[6]}; }


inline constexpr Vec3 Transform::backward(const Mat4& m) noexcept
{ return {m.coef[8], m.coef[9], m.coef[10]}; }


inline constexpr Vec3 Transform::translation(const Mat4& m) noexcept
{ return {m.coef[12], m.coef[13], m.coef[14]}; }