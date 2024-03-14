#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Vertex.hpp"

// Line Segment Added To Straight Skeleton
class Segment
{
public:
    Vertex sA;
    Vertex sB;

    Segment();
    ~Segment();
};

#endif //SEGMENT_HPP
