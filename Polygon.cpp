#include "Polygon.hpp"
#include <iostream>

using namespace std;

Polygon::Polygon()
{
    this->LAE.size = 0;
    this->LAV.size = 0;
}

Polygon::~Polygon()
{
}

void Polygon::addVertex(Vertex* v, int i, int total)
{
    if(this->LAV.size == 0) {
        this->LAV.head = v;
        this->LAV.tail = v;
        this->LAV.size++;
        return;
    }
    if(this->LAV.size > 0) {
        this->LAV.tail->adjVertexNext = v;
        v->adjVertexPrev = this->LAV.tail;
        v->adjVertexNext = this->LAV.head;
        this->LAV.head->adjVertexPrev = v;
        this->LAV.tail = v;
    }

    //cout << "..." << endl;
    //this->LAV.head->Info();
    //this->LAV.tail->Info();
    //cout << "..." << endl;

    this->LAV.size++;
}

void Polygon::addEdge(Vertex* v1, Vertex* v2, int i, int total)
{
    Edge* e = new Edge(v1, v2);
    //e->Info();
    v1->incidentEdges.push_back(e);
    v2->incidentEdges.push_back(e);

    if(this->LAE.size == 0) {
        this->LAE.head = e;
        this->LAE.tail = e;
        this->LAE.size++;
        return;
    }

    if(this->LAE.size > 0) {
        this->LAE.tail->adjEdgeNext = e;
        e->adjEdgePrev = this->LAE.tail;
        e->adjEdgeNext = this->LAE.head;
        this->LAE.head->adjEdgePrev = e;
        this->LAE.tail = e;
    }
    this->LAE.size++;
}