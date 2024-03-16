#include "Edge.hpp"
#include <iostream>

using namespace std;

// Construct/Destruct
Edge::Edge()
{
}

Edge::Edge(Vertex* A, Vertex* B)
{
    this->A = A;
    this->B = B;
}

Edge::~Edge()
{    
}

void Edge::Info()
{
}

void Edge::setEqn()
{
}