#ifndef CONVERSION_H
#define CONVERSION_H

#include "Quaternion.h"
#include "Matrix3.h"
#include "Matrix4.h"


namespace Math
{

Matrix4 toMatrix4(const Quaternion& q) noexcept;
Matrix4 toMatrix3(const Quaternion& m) noexcept;

} // End of namespace Math


#endif