/* ======== Static methods, pseudo-constructors ======== */
inline constexpr Matrix4 Matrix4::zero() noexcept
{
    return
    {
        .0f, .0f, .0f, .0f,
        .0f, .0f, .0f, .0f,
        .0f, .0f, .0f, .0f,
        .0f, .0f, .0f, .0f,
    };
}


inline constexpr Matrix4 Matrix4::identity() noexcept
{
    return
    {
        1.f, .0f, .0f, .0f,
        .0f, 1.f, .0f, .0f,
        .0f, .0f, 1.f, .0f,
        .0f, .0f, .0f, 1.f,
    };
}




/* =================== Methods =================== */
inline Matrix4 Matrix4::cofactor() const noexcept
{
    // Repeated values
    const f32 a11{coef[0]}, a12{coef[4]}, a13{coef[8]},  a14{coef[12]},
              a21{coef[1]}, a22{coef[5]}, a23{coef[9]},  a24{coef[13]},
              a31{coef[2]}, a32{coef[6]}, a33{coef[10]}, a34{coef[14]},
              a41{coef[3]}, a42{coef[7]}, a43{coef[11]}, a44{coef[15]},
              a22a33{a22 * a33}, a23a34{a23 * a34}, a24a32{a24 * a32},
              a24a33{a24 * a33}, a23a32{a23 * a32}, a22a34{a22 * a34},
              a33a42{a33 * a42}, a32a44{a32 * a44}, a34a43{a34 * a43},
              a33a44{a33 * a44}, a32a42{a34 * a42}, a32a43{a32 * a43},
              a12a23{a12 * a23}, a13a24{a13 * a24}, a14a22{a14 * a22},
              a14a23{a14 * a23}, a13a22{a13 * a22}, a12a24{a12 * a24},
              a31a44{a31 * a44}, a31a43{a31 * a43}, a13a21{a13 * a21},
              a14a21{a14 * a21}, a31a42{a31 * a42};

    Matrix4 co;

    *co.coef   = (a22a33 * a44) + (a23a34 * a42) + (a24a32 * a43)
                  - (a24a33 * a42) - (a23a32 * a44) - (a22a34 * a43);

    co.coef[1] = (a14 * a33a42) + (a13 * a32a44) + (a12 * a34a43)
                  - (a12 * a33a44) - (a13 * a32a42) - (a14 * a32a43);

    co.coef[2] = (a12a23 * a44) + (a13a24 * a42) + (a14a22 * a43)
                  - (a14a23 * a42) - (a13a22 * a44) - (a12a24 * a43);

    co.coef[3] = (a14 * a23a32) + (a13 * a22a34) + (a12 * a24a33)
                   - (a12 * a23a34) - (a13 * a24a32) - (a14 * a22a33);

    co.coef[4] = (a24a33 * a41) + (a23 * a31a44) + (a21 * a34a43)
                  - (a21 * a33a44) - (a23a34 * a41) - (a24 * a31a43);

    co.coef[5] = (a11 * a33a44) + (a13 * a34 * a41) + (a14 * a31a43)
                  - (a14 * a33 * a41) - (a13 * a31a44) - (a11 * a34a43);

    co.coef[6] = (a14a23 * a41) + (a13a21 * a44) + (a11 * a24 * a43)
                  - (a11 * a23 * a44) - (a13a24 * a41) - (a14a21 * a43);

    co.coef[7] = (a11 * a23a34) + (a13a24 * a31) + (a14a21 * a33)
                   - (a14a23 * a31) - (a13a21 * a34) - (a11 * a24a33);

    co.coef[8] = (a21 * a32a44) + (a22a34 * a41) + (a24 * a31a42)
                  - (a24a32 * a41) - (a22 * a31a44) - (a21 * a32a42);

    co.coef[9] = (a14 * a32 * a41) + (a12 * a31a44) + (a11 * a32a42)
                  - (a11 * a32a44) - (a12 * a34 * a41) - (a14 * a31a42);
    
    co.coef[10] = (a11 * a22 * a44) + (a12a24 * a41) + (a14a21 * a42)
                   - (a14a22 * a41) - (a12 * a21 * a44) - (a11 * a24 * a42);

    co.coef[11] = (a14a22 * a31) + (a12 * a21 * a34) + (a11 * a24a32)
                   - (a11 * a22a34) - (a12a24 * a31) - (a14a21 * a32);

    co.coef[12] = (a23a32 * a41) + (a22 * a31a43) + (a21 * a33a42)
                  - (a21 * a32a43) - (a22a33 * a41) - (a23 * a31a42);

    co.coef[13] = (a11 * a32a43) + (a12 * a33 * a41) + (a13 * a31a42)
                  - (a13 * a32 * a41) - (a12 * a31a43) - (a11 * a33a42);

    co.coef[14] = (a13a22 * a41) + (a12 * a21 * a43) + (a11 * a23 * a42)
                   - (a11 * a22 * a43) - (a12a23 * a41) - (a13a21 * a42);

    co.coef[15] = (a11 * a22a33) + (a12a23 * a31) + (a13a21 * a32)
                   - (a13a22 * a31) - (a12 * a21 * a33) - (a11 * a23a32);
    
    return co;
}


inline constexpr Matrix4 Matrix4::transposed() const noexcept
{
    return
    {
        coef[0], coef[4], coef[8] , coef[12],
        coef[1], coef[5], coef[9] , coef[13],
        coef[2], coef[6], coef[10], coef[14],
        coef[3], coef[7], coef[11], coef[15],
    };
}


inline constexpr Matrix4 Matrix4::adjugate() const noexcept
{ return cofactor().transposed(); }


inline constexpr f32 Matrix4::det() const noexcept
{
    const f32 a21{coef[1]},  a22{coef[5]},  a23{coef[9]},   a24{coef[13]},
              a31{coef[2]},  a32{coef[6]},  a33{coef[10]},  a34{coef[14]},
              a41{coef[3]},  a42{coef[7]},  a43{coef[11]},  a44{coef[15]},
              det1{(a33 * a44) - (a34 * a43)}, det2{(a31 * a44) - (a34 * a41)},
              det3{(a32 * a44) - (a34 * a42)}, det4{(a32 * a43) - (a33 * a42)},
              det5{(a31 * a43) - (a33 * a41)}, det6{(a31 * a42) - (a32 * a41)};

    return *coef      * ((a22 * det1) - (a23 * det3) + (a24 * det4))
           - coef[4]  * ((a21 * det1) - (a23 * det2) + (a24 * det5))
           + coef[8]  * ((a21 * det3) - (a22 * det2) + (a24 * det6))
           - coef[12] * ((a21 * det4) - (a22 * det5) + (a23 * det6));
}


inline Matrix4 Matrix4::inversed() const noexcept
{ return adjugate() / det(); }



inline constexpr f32 Matrix4::trace() const noexcept
{ return coef[0] + coef[5] + coef[10] + coef[15]; }



/* ================ Operator overloads ================= */
// This actually does m * *this
inline constexpr Matrix4& Matrix4::operator*=(const Matrix4& m) noexcept
{
    const f32 a11{coef[0]}, a12{coef[4]}, a13{coef[8]},  a14{coef[12]},
              a21{coef[1]}, a22{coef[5]}, a23{coef[9]},  a24{coef[13]},
              a31{coef[2]}, a32{coef[6]}, a33{coef[10]}, a34{coef[14]},
              a41{coef[3]}, a42{coef[7]}, a43{coef[11]}, a44{coef[15]};

    f32 ma1{*m.coef}, ma2{m.coef[4]}, ma3{m.coef[8]}, ma4{m.coef[12]};

    *coef   = (a11 * ma1) + (a12 * ma2) + (a13 * ma3) + (a14 * ma4);
    coef[1] = (a21 * ma1) + (a22 * ma2) + (a23 * ma3) + (a24 * ma4);
    coef[2] = (a31 * ma1) + (a32 * ma2) + (a33 * ma3) + (a34 * ma4);
    coef[3] = (a41 * ma1) + (a42 * ma2) + (a43 * ma3) + (a44 * ma4);

    ma1 = m.coef[1]; ma2 = m.coef[5]; ma3 = m.coef[9]; ma4 = m.coef[13];

    coef[4] = (a11 * ma1) + (a12 * ma2) + (a13 * ma3) + (a14 * ma4);
    coef[5] = (a21 * ma1) + (a22 * ma2) + (a23 * ma3) + (a24 * ma4);
    coef[6] = (a31 * ma1) + (a32 * ma2) + (a33 * ma3) + (a34 * ma4);
    coef[7] = (a41 * ma1) + (a42 * ma2) + (a43 * ma3) + (a44 * ma4);

    ma1 = m.coef[2]; ma2 = m.coef[6]; ma3 = m.coef[10]; ma4 = m.coef[14];

    coef[8]  = (a11 * ma1) + (a12 * ma2) + (a13 * ma3) + (a14 * ma4);
    coef[9]  = (a21 * ma1) + (a22 * ma2) + (a23 * ma3) + (a24 * ma4);
    coef[10] = (a31 * ma1) + (a32 * ma2) + (a33 * ma3) + (a34 * ma4);
    coef[11] = (a41 * ma1) + (a42 * ma2) + (a43 * ma3) + (a44 * ma4);

    ma1 = m.coef[3]; ma2 = m.coef[7]; ma3 = m.coef[11]; ma4 = m.coef[15];

    coef[12] = (a11 * ma1) + (a12 * ma2) + (a13 * ma3) + (a14 * ma4);
    coef[13] = (a21 * ma1) + (a22 * ma2) + (a23 * ma3) + (a24 * ma4);
    coef[14] = (a31 * ma1) + (a32 * ma2) + (a33 * ma3) + (a34 * ma4);
    coef[15] = (a41 * ma1) + (a42 * ma2) + (a43 * ma3) + (a44 * ma4);

    return *this;
}


inline constexpr Matrix4& Matrix4::operator/=(const f32 k) noexcept
{
    const f32 reciprocal{1.f / k};

    for (u8 i{0u}; i < MAT4_SIZE; ++i)
        coef[i] *= reciprocal;

    return *this;
}


inline constexpr Vec4 Matrix4::operator*(const Vec4& v) const noexcept
{
    const f32 x{v.xyz.x}, y{v.xyz.y}, z{v.xyz.z}, w{v.w};

    return
    {
        (coef[0] * x) + (coef[4] * y) + (coef[8]  * z) + (coef[12] * w),
        (coef[1] * x) + (coef[5] * y) + (coef[9]  * z) + (coef[13] * w),
        (coef[2] * x) + (coef[6] * y) + (coef[10] * z) + (coef[14] * w),
        (coef[3] * x) + (coef[7] * y) + (coef[11] * z) + (coef[15] * w)
    };
}


// Quite often, m is a static-built temporary matrix
inline Matrix4 Matrix4::operator*(const Matrix4& m) const noexcept
{
    Matrix4 res;

    const f32 mc11{*m.coef},     mc12{m.coef[4]},
              mc13{m.coef[8]},   mc14{m.coef[12]},
              mc21{m.coef[1]},   mc22{m.coef[5]},
              mc23{m.coef[9]},   mc24{m.coef[13]},
              mc31{m.coef[2]},   mc32{m.coef[6]},
              mc33{m.coef[10]},  mc34{m.coef[14]},
              mc41{m.coef[3]},   mc42{m.coef[7]},
              mc43{m.coef[11]},  mc44{m.coef[15]};
    
    f32 c1{coef[0]}, c2{coef[4]}, c3{coef[8]}, c4{coef[12]};

    // Row 1
    res.coef[0]  = (c1 * mc11) + (c2 * mc21) + (c3 * mc31) + (c4 * mc41);
    res.coef[4]  = (c1 * mc12) + (c2 * mc22) + (c3 * mc32) + (c4 * mc42);
    res.coef[8]  = (c1 * mc13) + (c2 * mc23) + (c3 * mc33) + (c4 * mc43);
    res.coef[12] = (c1 * mc14) + (c2 * mc24) + (c3 * mc34) + (c4 * mc44);

    // Row 2
    c1 = coef[1]; c2 = coef[5]; c3 = coef[9]; c4 = coef[13];

    res.coef[1]  = (c1 * mc11) + (c2 * mc21) + (c3 * mc31) + (c4 * mc41);
    res.coef[5]  = (c1 * mc12) + (c2 * mc22) + (c3 * mc32) + (c4 * mc42);
    res.coef[9]  = (c1 * mc13) + (c2 * mc23) + (c3 * mc33) + (c4 * mc43);
    res.coef[13] = (c1 * mc14) + (c2 * mc24) + (c3 * mc34) + (c4 * mc44);

    // Row 3
    c1 = coef[2]; c2 = coef[6]; c3 = coef[10]; c4 = coef[14];

    res.coef[2]  = (c1 * mc11) + (c2 * mc21) + (c3 * mc31) + (c4 * mc41);
    res.coef[6]  = (c1 * mc12) + (c2 * mc22) + (c3 * mc32) + (c4 * mc42);
    res.coef[10] = (c1 * mc13) + (c2 * mc23) + (c3 * mc33) + (c4 * mc43);
    res.coef[14] = (c1 * mc14) + (c2 * mc24) + (c3 * mc34) + (c4 * mc44);

    // Row 4
    c1 = coef[3]; c2 = coef[7]; c3 = coef[11]; c4 = coef[15];

    res.coef[3]  = (c1 * mc11) + (c2 * mc21) + (c3 * mc31) + (c4 * mc41);
    res.coef[7]  = (c1 * mc12) + (c2 * mc22) + (c3 * mc32) + (c4 * mc42);
    res.coef[11] = (c1 * mc13) + (c2 * mc23) + (c3 * mc33) + (c4 * mc43);
    res.coef[15] = (c1 * mc14) + (c2 * mc24) + (c3 * mc34) + (c4 * mc44);

    return res;
}

 
inline Matrix4 Matrix4::operator/(const f32 k) const noexcept
{
    const f32   reciprocal{1.f / k};
    Matrix4     res;

    for (u8 i{0u}; i < MAT4_SIZE; i += 4)
    {
        res.coef[i]     = coef[i] * reciprocal;
        res.coef[i + 1] = coef[i + 1] * reciprocal;
        res.coef[i + 2] = coef[i + 2] * reciprocal;
        res.coef[i + 3] = coef[i + 3] * reciprocal;
    }

    return res;
}


inline constexpr f32 Matrix4::operator[](const u8 i) const noexcept
{ return coef[i]; }


inline constexpr f32 Matrix4::operator()(const u8 i, const u8 j) const noexcept
{ return coef[j * MAT4_COL + i]; }


//#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& os, const Matrix4& mat) noexcept
{
    std::streamsize original = std::cout.precision();
    os << std::setprecision(2);

    for (u8 i{0u}; i < MAT4_COL; ++i)
    {
        u8 induction{i};
        
        os << "\n| ";
        for (u8 j{MAT4_COL}; j--; induction += MAT4_COL)
            os << std::setw(6) << mat.coef[induction] << ' ';

        os << " |";
    }

    os << std::setprecision(original);

    return os;
}
//#endif