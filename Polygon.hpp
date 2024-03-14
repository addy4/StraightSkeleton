#ifndef POLY_HPP
#define POLY_HPP

#include <vector>

#include "Edge.hpp"
#include "Vertex.hpp"

using namespace std;

// Each Iteration Will See A Different Polygon
class Polygon
{
public:
    vector<Edge> edges;
    vector<Vertex> vertices;

    Polygon(/* args */);
    ~Polygon();
};

#endif //POLY_HPP
