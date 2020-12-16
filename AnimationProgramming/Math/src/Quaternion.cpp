#include "Quaternion.h"
#include "Matrix3.h"
#include "Matrix4.h"

namespace Math
{

// Base on https://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/index.htm
// It is hacky, but it is logical, more efficient, and it works
Quaternion::Quaternion(const Matrix3& m) noexcept
{
    const f32 trace = m.trace();

    if (trace > .0f)
    {
        f32 tmp = sqrtf(trace + 1.f);

        s = tmp * .5f;

        tmp = .5f / tmp;

        v.x = (m.coef[5] - m.coef[7]) * tmp;
        v.y = (m.coef[6] - m.coef[2]) * tmp;
        v.z = (m.coef[1] - m.coef[3]) * tmp;
    }

    else
    {
        u8 i = 0;
        if (m.coef[4] > m.coef[0])      i = 1u;
        if (m.coef[8] > m.coef[4u * i]) i = 2u;

        const u8 next[3]    = {1u, 2u, 0u},
                 j          = next[i],
                 k          = next[j];

        f32 tmp = sqrtf((m(i, j) - (m(j, j) + m(k, k))) + 1.f);

        operator[](i) = tmp * .5f;

        if (tmp != .0f)
            tmp = .5f / tmp;

        v.z             = (m(k, j) - m(j, k)) * tmp;
        operator[](j)   = (m(j, i) + m(i, j)) * tmp;
        operator[](k)   = (m(k, i) + m(i, k)) * tmp;
    }
}

} // End of namespace Math