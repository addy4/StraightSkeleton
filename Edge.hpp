#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

class Edge
{
public:
    Line Eqn;
    Vertex x_A;
    Vertex x_B;
    Edge* adjEdgeA;
    Edge* adjEdgeB;
    Vertex collapsePoint;

    Edge();
    ~Edge();
};

#endif //EDGE_HPP