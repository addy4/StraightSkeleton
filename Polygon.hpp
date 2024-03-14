#ifndef POLY_HPP
#define POLY_HPP

#include <vector>
#include <list>

#include "Edge.hpp"
#include "Vertex.hpp"

using namespace std;

template<typename T>
class CircularConnectedList
{
public:
    list<T> entities;
};

// Each iteration will see a different polygon as wavefront
class Polygon
{
public:
    
    CircularConnectedList<Edge*> LAE; // List of active edges: LAE
    CircularConnectedList<Vertex*> LAV; // List of active vertices: LAV

    Vertex headVertex; // Head vertex points to tail vertex
    Edge headEdge; // Head edge points to tail edge

    Vertex tailVertex;
    Edge tailEdge;

    Polygon();
    ~Polygon();

    void addVertex(Vertex* v, int i, int total);
    void addEdge(Vertex* v1, Vertex* v2, int i, int total);
};

#endif //POLY_HPP
