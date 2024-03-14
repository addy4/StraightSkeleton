#include "Vertex.hpp"
#include <iostream>

using namespace std;

Vertex::Vertex()
{
}

Vertex::Vertex(double x_coord, double y_coord)
{
    this->adjVertexPrev = nullptr;
    this->adjVertexNext = nullptr;
    this->x_coord = x_coord;
    this->y_coord = y_coord;
}

Vertex::~Vertex()
{
}

void Vertex::Info()
{
    cout << "   XY: " << this->x_coord << ", " << this->y_coord << endl;
    if(adjVertexPrev) {
        cout << "   Previous XY: " << adjVertexPrev->x_coord << ", " << adjVertexPrev->y_coord << endl;
    }
    if(adjVertexNext) {
        cout << "   Next XY: " << adjVertexNext->x_coord << ", " << adjVertexNext->y_coord << endl;
    }
}