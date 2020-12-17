#include "Bone.h"
#include "Skeleton.h"
#include "Engine.h"

Bone::Bone(int index, Skeleton& skeleton)
    : invBindPos{}, pose{}, parent{GetSkeletonBoneParentIndex(index)}
{
    GetSkeletonBoneLocalBindTransform(index, pose.trans.x, pose.trans.y, pose.trans.z, pose.rot[0], pose.rot[1], pose.rot[2], pose.rot[3]);

    if (parent > -1)
    {
        // Genre invBindPose = inv(pose x skeleton.bone[parent].invBindPos)

        //invBindPos = pose.toMatrix().inversed() * skeleton.boneList[parent].invBindPos;
        //invBindPos = (skeleton.boneList[parent].invBindPos.inversed() * pose.toMatrix()).inversed();

        //invBindPos = (pose.toMatrix().inversed() * skeleton.boneList[parent].invBindPos).inversed();
        //std::cout << "Matrix inv inv xd = " << invBindPos << std::endl;

        invBindPos = (pose.toMatrix() * skeleton.boneList[parent].invBindPos.inversed()).inversed();

        std::cout << GetSkeletonBoneName(index) << " matrix = " << pose.toMatrix() << std::endl;
    }

    else
    {
        invBindPos = pose.toMatrix().inversed();
    }

    //  |- Bone -| |-------------- Pos ---------------|  |----------------------- Quat -----------------------|
    // (int index, float& posX, float& posY, float& posZ, float& quatW, float& quatX, float& quatY, float& quatZ)
}