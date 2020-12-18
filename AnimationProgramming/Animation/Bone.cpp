#include "Bone.h"
#include "Skeleton.h"
#include "Engine.h"

Bone::Bone(int index, const Skeleton& skeleton) noexcept
    : invBindPose{}, localBindPose{}, globalBindPose{}, localAnimPose{}, globalAnimPose{}, parentIndex{GetSkeletonBoneParentIndex(index)}
{
    GetSkeletonBoneLocalBindTransform(index, localBindPose.trans.x, localBindPose.trans.y, localBindPose.trans.z,
                                      localBindPose.rot.s, localBindPose.rot.v.x, localBindPose.rot.v.y, localBindPose.rot.v.z);

    // The bone has no parent
    if (index == 0)
    {
        invBindPose         = Math::Mat4::identity();
        globalBindPose      = localBindPose.toMatrix4();
        localAnimPose       = localBindPose;
        globalAnimPose      = globalBindPose;
    }

    // This bone has a parent
    else
    {
        globalBindPose  = skeleton.boneList[parentIndex].globalBindPose * localBindPose.toMatrix4();
        invBindPose     = globalBindPose.inversed();
        localAnimPose   = localBindPose;
        globalAnimPose  = globalBindPose;
    }
}