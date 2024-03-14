#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "Line.hpp"
#include <vector>

using namespace std;

class Edge;

class Vertex
{
public:
    double x_coord;
    double y_coord;
    double angle; // interior, part of polygon
    char angleType; // 'A', 'O'
    Line IncidentEdgeA;
    Line IncidentEdgeB;
    Line angleBisector;
    Vertex* adjVertexPrev;
    Vertex* adjVertexNext;
    vector<Edge*> incidentEdges;

    Vertex();
    Vertex(double xcord, double cord);
    ~Vertex();

    void Info();
    void computeAngleType();
    void setAngleBisector();
};

#endif // VERTEX_HPP