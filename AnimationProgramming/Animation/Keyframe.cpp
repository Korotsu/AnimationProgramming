#include "Keyframe.h"
#include "BonePose.h"

Keyframe::~Keyframe()
{
    delete[] poses;
}