/* ============== Inlined functions ============== */

inline f32 angle_from_cos(const f32 cosAngle)
{
    if (cosAngle < .0f || M_PI < cosAngle)
        return M_PI * 2.f - acosf(cosAngle);
    
    return acosf(cosAngle);
}