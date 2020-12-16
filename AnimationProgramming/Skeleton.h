#ifndef SKELETON_H
#define SKELETON_H

struct Bone;

struct Skeleton
{
    Bone* boneList;

    Skeleton(size_t size);
    ~Skeleton();

    void Draw() const;
};


#endif