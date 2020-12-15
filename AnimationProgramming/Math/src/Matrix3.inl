/* ======== Static methods, pseudo-constructors ======== */
inline constexpr Matrix3 Matrix3::zero() noexcept
{
    return
    {
        .0f, .0f, .0f,
        .0f, .0f, .0f,
        .0f, .0f, .0f
    };
}


inline constexpr Matrix3 Matrix3::identity() noexcept
{
    return
    {
        1.f, .0f, .0f,
        .0f, 1.f, .0f,
        .0f, .0f, 1.f
    };
}




/* =================== Methods =================== */
inline constexpr Matrix3 Matrix3::cofactor() const noexcept
{
    // Repeated values
    const f32 a11{coef[0]}, a12{coef[3]}, a13{coef[6]},
              a21{coef[1]}, a22{coef[4]}, a23{coef[7]},
              a31{coef[2]}, a32{coef[5]}, a33{coef[8]};

    return
    {
        (a22 * a33) - (a23 * a32), (a23 * a31) - (a21 * a33), (a21 * a32) - (a22 * a31),
        (a13 * a32) - (a12 * a33), (a11 * a33) - (a13 * a31), (a12 * a31) - (a11 * a32),
        (a11 * a23) - (a13 * a22), (a13 * a21) - (a11 * a23), (a11 * a22) - (a12 * a21)
    };
}


inline constexpr Matrix3 Matrix3::transposed() const noexcept
{
    return
    {
        coef[0], coef[3], coef[6],
        coef[1], coef[4], coef[7],
        coef[2], coef[5], coef[8]
    };
}


inline constexpr Matrix3 Matrix3::adjugate() const noexcept
{ return cofactor().transposed(); }


inline constexpr f32 Matrix3::det() const noexcept
{
    // Repeated values
    const f32 a12{coef[3]}, a13{coef[6]},
              a22{coef[4]}, a23{coef[7]},
              a32{coef[5]}, a33{coef[8]};

    return   coef[0] * (a22 * a33 - a23 * a32)
           - coef[1] * (a12 * a33 - a13 * a32)
           + coef[2] * (a12 * a23 + a13 * a22);
}


inline Matrix3 Matrix3::inversed() const noexcept
{ return adjugate() / det(); }



inline constexpr f32 Matrix3::trace() const noexcept
{ return coef[0] + coef[4] + coef[8]; }



/* ================ Operator overloads ================= */
// This actually does m * *this
inline constexpr Matrix3& Matrix3::operator*=(const Matrix3& m) noexcept
{
    // Repeated values
    const f32 a11{coef[0]}, a12{coef[3]}, a13{coef[6]},
              a21{coef[1]}, a22{coef[4]}, a23{coef[7]},
              a31{coef[2]}, a32{coef[5]}, a33{coef[8]};

    f32 ma1{m.coef[0]}, ma2{m.coef[3]}, ma3{m.coef[6]};

    coef[0] = (ma1 * a11) + (ma2 * a21) + (ma3 * a31);
    coef[1] = (ma1 * a12) + (ma2 * a22) + (ma3 * a32);
    coef[2] = (ma1 * a13) + (ma2 * a23) + (ma3 * a33);

    ma1 = m.coef[1]; ma2 = m.coef[4]; ma2 = m.coef[7];

    coef[3] = (ma1 * a11) + (ma2 * a21) + (ma3 * a31);
    coef[4] = (ma1 * a12) + (ma2 * a22) + (ma3 * a32);
    coef[5] = (ma1 * a13) + (ma2 * a23) + (ma3 * a33);

    ma1 = m.coef[2]; ma2 = m.coef[5]; ma2 = m.coef[8];

    coef[6] = (ma1 * a11) + (ma2 * a21) + (ma3 * a31);
    coef[7] = (ma1 * a12) + (ma2 * a22) + (ma3 * a32);
    coef[8] = (ma1 * a13) + (ma2 * a23) + (ma3 * a33);

    return *this;
}


inline constexpr Matrix3& Matrix3::operator/=(const f32 k) noexcept
{
    const f32 reciprocal{1.f / k};

    for (u8 i{0u}; i < MAT3_SIZE; ++i)
        coef[i] *= reciprocal;

    return *this;
}


inline constexpr Vec3 Matrix3::operator*(const Vec3& v) const noexcept
{
    return
    {
        (coef[0] * v.x) + (coef[3] * v.y) + (coef[6] * v.z),
        (coef[1] * v.x) + (coef[4] * v.y) + (coef[7] * v.z),
        (coef[2] * v.x) + (coef[5] * v.y) + (coef[8] * v.z)
    };
}


inline Matrix3 Matrix3::operator*(const Matrix3& m) const noexcept
{
    Matrix3 res;

    // Repeated values
    const f32 a11{m.coef[0]}, a12{m.coef[3]}, a13{m.coef[6]},
              a21{m.coef[1]}, a22{m.coef[4]}, a23{m.coef[7]},
              a31{m.coef[2]}, a32{m.coef[5]}, a33{m.coef[8]};

    f32 ma1{coef[0]}, ma2{coef[3]}, ma3{coef[6]};

    res.coef[0] = (ma1 * a11) + (ma2 * a21) + (ma3 * a31);
    res.coef[1] = (ma1 * a12) + (ma2 * a22) + (ma3 * a32);
    res.coef[2] = (ma1 * a13) + (ma2 * a23) + (ma3 * a33);

    ma1 = coef[1]; ma2 = coef[4]; ma2 = coef[7];

    res.coef[3] = (ma1 * a11) + (ma2 * a21) + (ma3 * a31);
    res.coef[4] = (ma1 * a12) + (ma2 * a22) + (ma3 * a32);
    res.coef[5] = (ma1 * a13) + (ma2 * a23) + (ma3 * a33);

    ma1 = coef[2]; ma2 = coef[5]; ma2 = coef[8];

    res.coef[6] = (ma1 * a11) + (ma2 * a21) + (ma3 * a31);
    res.coef[7] = (ma1 * a12) + (ma2 * a22) + (ma3 * a32);
    res.coef[8] = (ma1 * a13) + (ma2 * a23) + (ma3 * a33);

    return res;
}

 
inline Matrix3 Matrix3::operator/(const f32 k) const noexcept
{
    const f32   reciprocal{1.f / k};
    Matrix3     res;

    for (u8 i{0u}; i < MAT3_SIZE; i += 3)
    {
        res.coef[i]     = coef[i] * reciprocal;
        res.coef[i + 1] = coef[i + 1] * reciprocal;
        res.coef[i + 2] = coef[i + 2] * reciprocal;
    }

    return res;
}


inline constexpr f32 Matrix3::operator[](const u8 i) const noexcept
{ return coef[i]; }


inline constexpr f32 Matrix3::operator()(const u8 i, const u8 j) const noexcept
{ return coef[j * MAT3_COL + i]; }


#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& os, const Matrix3& mat) noexcept
{
    std::streamsize original = std::cout.precision();
    os << std::setprecision(2);

    for (u8 i{0u}; i < MAT3_COL; ++i)
    {
        u8 induction{i};
        
        os << "\n| ";
        for (u8 j{MAT3_COL}; j--; induction += MAT3_COL)
            os << std::setw(6) << mat.coef[induction] << ' ';

        os << " |";
    }

    os << std::setprecision(original);

    return os;
}
#endif