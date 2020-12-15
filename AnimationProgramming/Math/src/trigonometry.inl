/* ============== Inlined functions ============== */

inline f32 angle_from_cos(const f32 cosAngle)
{
    if (cosAngle < .0f || PI < cosAngle)
        return PI * 2.f - acosf(cosAngle);
    
    return acosf(cosAngle);
}