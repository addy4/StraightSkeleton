#include "Edge.hpp"
#include <iostream>

using namespace std;

// Construct/Destruct
Edge::Edge()
{
}

Edge::Edge(Vertex A, Vertex B)
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
    cout << this->x_A.x_coord << endl;
    cout << this->x_A.y_coord << endl;
    cout << this->x_B.x_coord << endl;
    cout << this->x_B.y_coord << endl;
    return;
}