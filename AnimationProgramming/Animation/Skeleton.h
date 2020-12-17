#ifndef SKELETON_H
#define SKELETON_H

struct Bone;
namespace Math
{
    struct Vector3;
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

    void MoveBone(int boneIndex, const Math::Vector3& translation) noexcept;

    void Draw() const;

    void GatherMatrixPalette() noexcept;

    Skeleton& operator=(Skeleton&&) = default;
};


#endif