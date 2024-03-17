#include "Segment.hpp"
#include <utility>

using namespace std;

Segment::Segment(pair<double,double> vA, pair<double,double> vB)
{
    this->source = vA;
    this->dest = vB;
}

Segment::~Segment()
{
}