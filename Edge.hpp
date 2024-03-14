#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

class Edge
{
public:
    Line Eqn;
    Vertex* A;
    Vertex* B;
    Edge* adjEdgePrev;
    Edge* adjEdgeNext;
    Vertex collapsePoint;

    Edge();
    Edge(Vertex* A, Vertex* B);
    ~Edge();

    void Info();
    void setEqn();
};

#endif //EDGE_HPP