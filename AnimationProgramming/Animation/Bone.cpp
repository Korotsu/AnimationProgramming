#include "Bone.h"
#include "Skeleton.h"
#include "Engine.h"

Bone::Bone(int index, Skeleton& skeleton)
    : invBindPose{}, pose{}, parentIndex{GetSkeletonBoneParentIndex(index)}
{
    GetSkeletonBoneLocalBindTransform(index, pose.trans.x, pose.trans.y, pose.trans.z,
                                      pose.rot.s, pose.rot.v.x, pose.rot.v.y, pose.rot.v.z);

    // The bone has no parent
    if (index == 0)
        invBindPose = Math::Mat4::identity();

    // This bone has a parent
    else
    {
        const Bone& parent{skeleton.boneList[parentIndex]};
        invBindPose = parent.pose.toMatrix4().inversed() * parent.invBindPose;
    }
}