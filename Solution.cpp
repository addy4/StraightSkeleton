#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

#include "Line.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int NUM_V = 5;
    int i = 0;

    vector<Vertex*> IpVertices; // Input

    Vertex* addedVertex;
    addedVertex = new Vertex(1, 5);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(4, 1);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(8, 3);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(7, 7);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(3, 9);
    IpVertices.push_back(addedVertex);
    
    Polygon poly;
    Vertex* prev = IpVertices[i];
    poly.addVertex(prev, i, NUM_V);

    i++;

    while(i < NUM_V) {

        Vertex* currVertex = IpVertices[i];
        poly.addVertex(currVertex, i, NUM_V);

        // Vertices...
        for(auto v : poly.LAV.entities) {
            v->Info();
        }

        cout << endl;

        poly.addEdge(prev, currVertex, i - 1, NUM_V);
        
        i++;
    }

    for(auto e : poly.LAE.entities) {
        e->Info();
    }

    for(auto v : poly.LAV.entities) {
        v->Info();
    }

    Vertex* vt = poly.LAV.entities.front();

    for(int l = 0; l <= NUM_V; l++) {
        vt->Info();
        vt = vt->adjVertexNext;
    }

    Edge* et = poly.LAE.entities.front();

    for(int l = 0; l <= NUM_V; l++) {
        et->Info();
        //et = et->adjEdgeNext;
    }

    return 0;
}
