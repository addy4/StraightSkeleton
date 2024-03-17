#include "Utils.hpp"
#include "Line.hpp"
#include "Vertex.hpp"
#include "Segment.hpp"
#include <utility>
#include <cmath>
#include <climits>
#include <cstdint>
#include <iostream>

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

bool Utils::coincide(Vertex A, Vertex B)
{
    if(abs(B.x_coord - A.x_coord) > 0.75) {
        return false;
    }
    if(abs(B.y_coord - A.y_coord) > 0.75) {
        return false;
    }
    return true;
}

pair<double,double> Utils::IntersectionPoint(Line liA, Line liB)
{
    liA.constant = -1 * liA.constant;
    liB.constant = - 1 * liB.constant;

    // Line A: a1x + b1y = c1
    // Line B: a2x + b2y = c2

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

double Utils::distanceFromLine(pair<double,double> Intersection, Line L)
{
    double denominator = sqrt(L.x_coeff * L.x_coeff + L.y_coeff * L.y_coeff);
    double numerator = abs(L.x_coeff * Intersection.first + L.y_coeff * Intersection.second + L.constant);
    return numerator/denominator;
}

pair<double,double> Utils::vectorSum(Line A, Line B)
{
    double idir = A.unitVectorIcoeff + B.unitVectorIcoeff;
    double jdir = A.unitVectorJcoeff + B.unitVectorJcoeff;
    return make_pair(idir, jdir);
}

// Acute angle between lines returned in radians and further converted to degrees
double Utils::angleBwLines(Line R, Line S)
{
    double mSlopeR = -1 * (R.x_coeff/R.y_coeff);
    double mSlopeS = -1 * (S.x_coeff/S.y_coeff);

    if(mSlopeR * mSlopeS == -1) {
        return 90;
    }

    double tanTheta = (mSlopeS - mSlopeR)/(1 + mSlopeS * mSlopeR);
    return atan(tanTheta)*180/3.1415;
}

// Print wavefront
void Utils::printPolygon(waveFront wave)
{
    for(int l = 0; l < wave.size() - 1; l++)
    {
        cout << wave[l].first << ", " << wave[l].second << ", " << wave[l+1].first << ", " << wave[l+1].second << endl;
    }
    cout << wave[wave.size() - 1].first << ", " << wave[wave.size() - 1].second << ", " << wave[0].first << ", " << wave[0].second << endl;
}

void Utils::printWaveFront(waveFront wave)
{
    for(auto wavePoint : wave)
    {
        cout << wavePoint.first << ", " << wavePoint.second << endl;
    }
}

void Utils::printSkeleton(vector<Segment> skeleton)
{
    for(auto s : skeleton) {
        cout << s.source.first << ", " << s.source.second << ", " << s.dest.first << ", " << s.dest.second << endl;
    }
}