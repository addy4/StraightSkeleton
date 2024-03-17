#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <utility>

using namespace std;

// Line Segment Added To Straight Skeleton
class Segment
{
public:
    pair<double,double> source;
    pair<double,double>  dest;

    Segment(pair<double,double> vA, pair<double,double> vB);
    ~Segment();
};

#endif //SEGMENT_HPP
