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
    T* head;
    T* tail;
    int size;
};

// Each iteration will see a different polygon as wavefront
class Polygon
{
public:
    
    CircularConnectedList<Edge> LAE; // List of active edges: LAE
    CircularConnectedList<Vertex> LAV; // List of active vertices: LAV

    Polygon();
    ~Polygon();

    void addVertex(Vertex* v);
    void removeVertex(Vertex* v);
    void addEdge(Vertex* v1, Vertex* v2, int i, int total);
};

#endif //POLY_HPP
