#include "Bone.h"
#include "Skeleton.h"
#include "Engine.h"

Bone::Bone(int index, Skeleton& skeleton)
    : invBindPose{}, localPose{}, globalPose{}, parentIndex{ GetSkeletonBoneParentIndex(index) }
{
    GetSkeletonBoneLocalBindTransform(index, localPose.trans.x, localPose.trans.y, localPose.trans.z,
                                      localPose.rot.s, localPose.rot.v.x, localPose.rot.v.y, localPose.rot.v.z);

    // The bone has no parent
    if (index == 0)
    {
        invBindPose = Math::Mat4::identity();
        globalPose   = localPose.toMatrix4();
    }

    // This bone has a parent
    else
    {
        globalPose = skeleton.boneList[parentIndex].globalPose * localPose.toMatrix4();
        invBindPose = globalPose.inversed();
    }
}

void Bone::Move(Math::vec3 translation, const Skeleton& skeleton)
{
    localPose.trans += translation;
    globalPose = skeleton.boneList[parentIndex].globalPose * localPose.toMatrix4();
    invBindPose = globalPose.inversed();
}