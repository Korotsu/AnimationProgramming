#include "BonePose.h"
#include "conversion.h"
#include "Transform.h"

Math::Matrix4 BonePose::toMatrix4() const noexcept
{ return Math::Transform::translation(trans) * Math::toMatrix4(rot) * Math::Transform::scaling(scale); }