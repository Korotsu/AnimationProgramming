#include "Skeleton.h"
#include "Bone.h"

Skeleton::Skeleton(size_t size)
    : bone{ new Bone[size] }
{

}

Skeleton::~Skeleton()
{
    delete [] bone;
}