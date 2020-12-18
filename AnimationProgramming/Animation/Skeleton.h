#ifndef SKELETON_H
#define SKELETON_H

struct Bone;
namespace Math
{
    struct Vector3;
    struct Quaternion;
    struct Matrix4;
}

struct Skeleton
{
    size_t          size    {0u};
    Bone*           boneList{nullptr};
    Math::Matrix4*  palette {nullptr};

    Skeleton() = default;
    ~Skeleton();

    void Init() noexcept;

    void SetBoneTransform(int boneIndex, const Math::Vector3& translation, const Math::Quaternion& rot) noexcept;

    void Draw() const;

    void GatherMatrixPalette() noexcept;

    void ApplyAnimTransform(const char* animName, size_t keyframe) noexcept;

    Skeleton& operator=(Skeleton&&) = default;
};


#endif