#ifndef UTILS_HPP
#define UTILS_HPP

#include "Line.hpp"
#include <utility>

using namespace std;

class Utils
{
public:
    Utils();
    ~Utils();

    static int dotProductSign(Line inci1, Line inci2);
    static pair<double,double> IntersectionPoint(Line liA, Line liB);
};

#endif //UTILS_HPP
