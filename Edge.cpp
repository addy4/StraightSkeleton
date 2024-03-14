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

// Utils
void Edge::Info()
{
    cout << "Vertices.........." << endl;
    cout << "   " << endl;
    this->A->Info();
    this->B->Info();

    return;
}

void Edge::setEqn()
{
    this->Eqn = Line(this->A->x_coord, this->A->y_coord, this->B->x_coord, this->B->y_coord);
}