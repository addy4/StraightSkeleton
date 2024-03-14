#include "Polygon.hpp"
#include <iostream>

using namespace std;

Polygon::Polygon()
{
}

Polygon::~Polygon()
{
}

void Polygon::addVertex(Vertex* v, int i, int total)
{
    // add vertex to LAV
    // LAV.back().adjVertexNext = v;
    // v.adjVertexPrev = LAV.back();
    // LAV.push_back(v);
    // if i == total - 1
    //      v.adjVertexNext = LAV.front()
    //      LAV.front().prev = v;
    
    if(i > 0) {
        LAV.entities.back()->adjVertexNext = v;
        v->adjVertexPrev = LAV.entities.back();
    }  
    if(i == total - 1) {
        v->adjVertexNext = LAV.entities.front();
        LAV.entities.front()->adjVertexPrev = v;
    }
    LAV.entities.push_back(v);
}

void Polygon::addEdge(Vertex* v1, Vertex* v2, int i, int total)
{
    // Edge e(v1, v2);
    // v1.incidentEdges.push_back(e);
    // v2.incidentEdges.push_back(e);
    // add e to LAE
    // LAE.back().adjEdgeNext = e;
    // e.adjEdgePrev = LAE.back();
    // LAE.push_back(e);
    // if i == total - 1
    //      e.adjEdgeNext = LAE.front()
    //      LAE.front().prev = e;

    Edge* e = new Edge(v1, v2);

    cout << "qwqwqw" << endl;

    v1->incidentEdges.push_back(e);
    v2->incidentEdges.push_back(e);

    cout << "ttt" << endl;

    if(i > 0) {
        LAE.entities.back()->adjEdgeNext = e;
        e->adjEdgePrev = LAE.entities.back();
    }

    if(i == total - 1) {
        e->adjEdgeNext = LAE.entities.front();
        LAE.entities.front()->adjEdgePrev = e;
    }
    LAE.entities.push_back(e);
    cout << "qs" << endl;
}