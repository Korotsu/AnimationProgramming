/* ================= Inlined conversion methods ================= */

inline Matrix4 toMatrix4(const Quaternion& q) noexcept
{
    const float x2{q.x() * q.x()},
                y2{q.y() * q.y()},
                z2{q.z() * q.z()},
                xy{q.x() * q.y()},
                yz{q.y() * q.z()},
                xz{q.x() * q.z()},
                wx{q.s * q.x()},
                wy{q.s * q.y()},
                wz{q.s * q.z()},
                s_2{2.f / q.length2()};

    // Column-major
    return
    {
        1.f - s_2 * (y2 + z2),  s_2 * (xy - wz),        s_2 * (xz + wy),        .0f,
        s_2 * (xy + wz),        1.f - s_2 * (x2 + z2),  s_2 * (yz - wx),        .0f,
        s_2 * (xz - wy),        s_2 * (yz + wx),        1.f - s_2 * (x2 + y2),  .0f,
        .0f,                    .0f,                    .0f,                    1.f
    };
}


inline Matrix3 toMatrix3(const Quaternion& q) noexcept
{
    const float x2{q.x() * q.x()},
                y2{q.y() * q.y()},
                z2{q.z() * q.z()},
                xy{q.x() * q.y()},
                yz{q.y() * q.z()},
                xz{q.x() * q.z()},
                wx{q.s * q.x()},
                wy{q.s * q.y()},
                wz{q.s * q.z()},
                s_2{2.f / q.length2()};

    // Column-major
    return
    {
        1.f - s_2 * (y2 + z2),  s_2 * (xy - wz),        s_2 * (xz + wy),
        s_2 * (xy + wz),        1.f - s_2 * (x2 + z2),  s_2 * (yz - wx),
        s_2 * (xz - wy),        s_2 * (yz + wx),        1.f - s_2 * (x2 + y2)
    };
}