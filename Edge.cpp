#include "Edge.hpp"
#include <iostream>

using namespace std;

// Construct/Destruct
Edge::Edge()
{
}

Edge::Edge(Vertex* A, Vertex* B)
{
    this->x_A = A;
    this->x_B = B;
}

Edge::~Edge()
{    
}

// Utils
void Edge::Info()
{
    cout << "Vertices.........." << endl;
    cout << "   " << endl;
    this->x_A->Info();
    this->x_B->Info();

    return;
}