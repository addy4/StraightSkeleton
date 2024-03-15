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
    /*
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
    */

    int NUM_V = 4;
    int i = 0;

    vector<Vertex*> IpVertices; // Input

    Vertex* addedVertex;
    //addedVertex = new Vertex(1, 5);
    //IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(4, 1);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(8, 3);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(7, 7);
    IpVertices.push_back(addedVertex);
    addedVertex = new Vertex(3, 9);
    IpVertices.push_back(addedVertex);
    
    Polygon poly;
    Vertex* head = IpVertices[i];
    Vertex* prev = IpVertices[i];
    poly.addVertex(prev, i, NUM_V);
    prev->Info();
    i++;

    while(i < NUM_V) {

        Vertex* currVertex = IpVertices[i];
        currVertex->Info();
        poly.addVertex(currVertex, i, NUM_V);
        poly.addEdge(prev, currVertex, i - 1, NUM_V);
        prev = currVertex;
        i++;
    }
    poly.addEdge(prev, head, i, NUM_V);

    Vertex* itV = poly.LAV.head;

    i = 0;

    cout << endl;

    while (i <= NUM_V)
    {
        itV->Info();
        itV->setAngleBisector();
        itV->angleBisector.Show();
        itV = itV->adjVertexNext;
        i++;
    }
    
    Edge* itE = poly.LAE.head;

    i = 0;

    while (i <= NUM_V)
    {
        itE->Info();
        itE = itE->adjEdgeNext;
        i++;
    }
    

    return 0;
}
