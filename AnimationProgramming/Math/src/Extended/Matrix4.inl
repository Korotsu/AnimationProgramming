/* =================== Internal, private =================== */
constexpr inline void Matrix4::update_det() noexcept
{
    if (std::isnan(det_))
    {
        // Repeated values
        const f32 c4{coef[1]},  c5{coef[5]},    c6{coef[9]},    c7{coef[13]},
                  c8{coef[2]},  c9{coef[6]},    c10{coef[10]},  c11{coef[14]},
                  c12{coef[3]}, c13{coef[7]},   c14{coef[11]},  c15{coef[15]},
                  det1{(c10 * c15) - (c11 * c14)}, det2{(c8 * c15) - (c11 * c12)},
                  det3{(c9  * c15) - (c11 * c13)}, det4{(c9 * c14) - (c10 * c13)},
                  det5{(c8  * c14) - (c10 * c12)}, det6{(c8 * c13) - (c9  * c12)};

        det =   coef[0]  * ((c5 * det1) - (c6 * det3) + (c7 * det4))
              - coef[4]  * ((c4 * det1) - (c6 * det2) + (c7 * det5))
              + coef[8]  * ((c4 * det3) - (c5 * det2) + (c7 * det6))
              - coef[12] * ((c4 * det4) - (c5 * det5) + (c6 * det6));
    }
}




/* =================== Constructors =================== */
constexpr inline Matrix4::Matrix4(const Math::Mat4& base_,
                                     const f32 _det) noexcept
    : base{base_}, det_{_det}
{}


constexpr inline Matrix4::Matrix4(const f32 a11, const f32 a12,
                                     const f32 a13, const f32 a14,
                                     const f32 a21, const f32 a22,
                                     const f32 a23, const f32 a24,
                                     const f32 a31, const f32 a32,
                                     const f32 a33, const f32 a34,
                                     const f32 a41, const f32 a42,
                                     const f32 a43, const f32 a44,
                                     const f32 _det) noexcept
    : base{a11, a21, a31, a41,
           a12, a22, a32, a42,
           a13, a23, a33, a43,
           a14, a24, a34, a44},
      det_{_det}
{}




/* ======== Static methods, pseudo-constructors ======== */
constexpr inline Matrix4 Matrix4::zero() noexcept
{ return {Math::Mat4::zero(), .0f}; }


constexpr inline Matrix4 Matrix4::identity() noexcept
{ return { Math::Mat4::identity(), 1.f}; }



/* =================== Methods =================== */
inline Matrix4 Matrix4::co_factor() const noexcept
{ return base.co_factor(); }


inline Matrix4 Matrix4::transposed() const noexcept
{ return {base.transposed(), det}; }


inline Matrix4 Matrix4::adjugate() const noexcept
{ return base.adjugate(); }


inline f32 Matrix4::det() noexcept
{
    update_det();
    return det_;
}


inline Matrix4 Matrix4::inversed() noexcept
{ return base.adjugate() / det(), 1.f / det_}; }


inline void Matrix4::set_column(const u8 i, const Vec4& v) noexcept
{
    const u8 col = (i * MAT4_COL) & (MAT_SIZE - MAT_COL - 1);

    coef[col]       = v.x;
    coef[col + 1]   = v.y;
    coef[col + 2]   = v.z;
    coef[col + 3]   = v.w;

    det_ = NAN;
}


inline Math::Vec4 Matrix4::get_column(const u8 i) const noexcept
{
    const u8 col = (i * MAT4_COL) & (MAT_SIZE - MAT_COL - 1);

    return {coef[col], coef[col + 1], coef[col + 2], coef[col + 3]};
}




/* ================ Operator overloads ================= */
inline Matrix4& Matrix4::operator*=(const Matrix4& m)
{
    base *= m.base;
    det_ *= m.det_;

    return *this;
}


inline Matrix4& Matrix4::operator/=(const f32 k)
{
    const f32 k2{k * k};

    base /= k;
    det_ *= 1.f / (k2 * k2);

    return *this;
}


inline Vec4 Matrix4::operator*(const Math::Vec4& v) const noexcept
{ return base * v; }


// Quite often, m is a static-built temporary matrix
inline Matrix4 Matrix4::operator*(const Matrix4& m) const noexcept
{ return {base * m, det_ * m.det_}; }


inline Matrix4 Matrix4::operator/(const f32 k) const noexcept
{
    const f32 k2{k * k};

    return {base / k, det_ * (1.f / (k2 * k2))};
}


inline f32 Matrix4::operator[](u8 i) const
{ return base[i]; }


#ifdef DEBUG
inline std::ostream& operator<<(std::ostream& os, const Matrix4& m)
{
    return os << m.base << "\ndet = " << mat.det_;
}
#endif