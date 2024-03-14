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

    void insertEntity(const T& item)
    {
        entities.push_back(item);
    }

    void removeEntity(const T& item)
    {
        entities.remove(item);
    }

    void removeByIterator(typename std::list<T>::iterator it) 
    {
        entities.erase(it);
    }
};

// Each Iteration Will See A Different Polygon
class Polygon
{
public:
    
    vector<Edge> edges;
    vector<Vertex> vertices;
    
    CircularConnectedList<Edge> LAE; // List of active edges
    CircularConnectedList<Vertex> LAV; // List of active vertices

    Polygon(/* args */);
    ~Polygon();

    void addEdge(Vertex v1, Vertex v2);
};

#endif //POLY_HPP
