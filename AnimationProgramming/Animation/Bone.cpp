#include "Bone.h"
#include "Skeleton.h"
#include "Engine.h"

Bone::Bone(int index, Skeleton& skeleton)
    : invBindPose{}, localPose{}, globaPose{}, parentIndex{ GetSkeletonBoneParentIndex(index) }
{
    GetSkeletonBoneLocalBindTransform(index, localPose.trans.x, localPose.trans.y, localPose.trans.z,
        localPose.rot.s, localPose.rot.v.x, localPose.rot.v.y, localPose.rot.v.z);

    // The bone has no parent
    if (index == 0)
    {
        invBindPose = Math::Mat4::identity();
        globaPose   = Math::Mat4::identity();
    }

    // This bone has a parent
    else
    {
        const Bone& parent{skeleton.boneList[parentIndex]};
        //invBindPose = parent.localPose.toMatrix4().inversed() * parent.invBindPose;
        //invBindPose = (localPose.toMatrix4() * skeleton.boneList[parentIndex].invBindPose.inversed()).inversed();
        globaPose = parent.globaPose * localPose.toMatrix4();
        invBindPose = globaPose.inversed();
    }
}