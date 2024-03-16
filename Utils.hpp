#ifndef UTILS_HPP
#define UTILS_HPP

#include "Line.hpp"
#include "Vertex.hpp"
#include <utility>

using namespace std;

class Utils
{
public:
    Utils();
    ~Utils();

    static int dotProductSign(Line inci1, Line inci2);
    static pair<double,double> IntersectionPoint(Line liA, Line liB);
    static double distanceFromLine(Vertex P, Line L);
    static pair<double,double> vectorSum(Line A, Line B);
    static double angleBwLines(Line A, Line B);
};

#endif //UTILS_HPP
