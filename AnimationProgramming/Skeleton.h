#ifndef SKELETON_H
#define SKELETON_H

#include <vector>

struct Bone;

struct Skeleton
{
    size_t    size    {0u};
    Bone*           boneList{nullptr};

    Skeleton() = default;
    ~Skeleton();

    void init();

    void Draw() const;

    Skeleton& operator=(Skeleton&&) = default;
};


#endif