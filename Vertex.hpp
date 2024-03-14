#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "Line.hpp"

class Vertex
{
public:
    double x_coord;
    double y_coord;
    double angle; // interior, part of polygon
    Line angleBisector;
    Vertex* adjVertexA;
    Vertex* adjVertexB;

    Vertex();
    Vertex(double xcord, double cord);
    ~Vertex();
};

#endif // VERTEX_HPP
