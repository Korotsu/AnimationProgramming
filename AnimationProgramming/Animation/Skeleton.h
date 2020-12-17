#ifndef SKELETON_H
#define SKELETON_H

struct Bone;
namespace Math
{ struct Vector3; }

struct Skeleton
{
    size_t  size    {0u};
    Bone*   boneList{nullptr};

    Skeleton() = default;
    ~Skeleton();

    void Init() noexcept;

    void MoveBone(int boneIndex, const Math::Vector3& translation) noexcept;

    void Draw() const;

    Skeleton& operator=(Skeleton&&) = default;
};


#endif