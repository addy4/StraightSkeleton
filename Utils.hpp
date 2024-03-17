#ifndef UTILS_HPP
#define UTILS_HPP

#include "Line.hpp"
#include "Vertex.hpp"
#include <utility>

using namespace std;

typedef vector<pair<double,double>> waveFront;

class Utils
{
public:
    Utils();
    ~Utils();

    static bool coincide(Vertex A, Vertex B);
    static int dotProductSign(Line inci1, Line inci2);
    static pair<double,double> IntersectionPoint(Line liA, Line liB);
    static double distanceFromLine(pair<double,double> Intersection, Line L);
    static pair<double,double> vectorSum(Line A, Line B);
    static double angleBwLines(Line A, Line B);
    static void printPolygon(waveFront wave);
    static void printWaveFront(waveFront wave);
};

#endif //UTILS_HPP
