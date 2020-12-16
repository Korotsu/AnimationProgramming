#ifndef SKELETON_H
#define SKELETON_H

struct Bone;

struct Skeleton
{
    Bone* bone;

    Skeleton(size_t size);
    ~Skeleton();
};


#endif