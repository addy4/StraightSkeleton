#include "Utils.hpp"
#include "Line.hpp"
#include "Vertex.hpp"
#include <utility>
#include <cmath>
#include <climits>
#include <cstdint>

using namespace std;

int Utils::dotProductSign(Line incident1, Line incident2)
{
    if((incident1.icoeff * incident2.icoeff + incident1.jcoeff * incident2.jcoeff) > 0) {
        return +1;
    }
    else if((incident1.icoeff * incident2.icoeff + incident1.jcoeff * incident2.jcoeff) < 0) {
        return -1;
    }
    return 0;
}

pair<double,double> Utils::IntersectionPoint(Line liA, Line liB)
{
    liA.constant = -1 * liA.constant;
    liB.constant = - 1 * liB.constant;

    // Line A: a1x + b1y = c1
    // Line B: a2x + b2y = c2

    liA.Show();
    liB.Show();

    double determinant = liA.x_coeff * liB.y_coeff - liB.x_coeff * liA.y_coeff;

    if(determinant == 0) 
    {
        // Parallel
        return make_pair(INT16_MAX, INT16_MAX);
    }
    else
    {
        double x = (liA.constant * liB.y_coeff - liB.constant * liA.y_coeff)/determinant;
        double y = (liA.x_coeff * liB.constant - liB.x_coeff * liA.constant)/determinant;
        return make_pair(x, y);
    }
    return make_pair(INT16_MIN, INT16_MIN);
}