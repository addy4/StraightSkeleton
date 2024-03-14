#include "Polygon.hpp"

Polygon::Polygon()
{
}

Polygon::~Polygon()
{
}

void Polygon::addEdge(Vertex v1, Vertex v2)
{
    Edge e(v1, v2);
    v1.incidentEdges.push_back(&e);
    v2.incidentEdges.push_back(&e);
    this->LAV.entities.push_back(v1);
    this->LAV.entities.push_back(v2);
    this->LAE.entities.push_back(e);
}