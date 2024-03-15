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
#include <utility>

#include "Line.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"
#include "Utils.hpp"

using namespace std;

void showCurrentWavefront(Polygon poly);
void generateStraightSkeleton(Polygon poly);

int main(int argc, char const *argv[])
{
    // Input vertices
    vector<pair<int,int>> network = {make_pair(4, 1), make_pair(8, 3), make_pair(7, 7), make_pair(3, 9)};
    
    // Creating polygon
    int vertexNumber = 0;
    Polygon poly;

    Vertex* prev;
    Vertex* head = new Vertex(network[vertexNumber].first, network[vertexNumber].second);
    prev = head;
    
    poly.addVertex(head);
    vertexNumber++;

    while (vertexNumber < network.size())
    {
        Vertex* currVertex = new Vertex(network[vertexNumber].first, network[vertexNumber].second); 
        poly.addVertex(currVertex);
        prev = currVertex;
        vertexNumber++;  
    }

    showCurrentWavefront(poly);
    //generateStraightSkeleton(poly);
    
    pair<double,double> pdd = Utils::IntersectionPoint(prev->IncidentEdgeA, prev->IncidentEdgeB);
    cout << pdd.first << endl;
    cout << pdd.second << endl;

    return 0;
}

void showCurrentWavefront(Polygon poly)
{
    /* debugging polygon for straight skeleton */

    Vertex* vertexIterator = poly.LAV.head;
    int vertexNumber = 0;
    while (vertexNumber < poly.LAV.size + 1)
    {
        vertexIterator->Info();
        vertexIterator->setAngleBisector();
        vertexIterator->angleBisector.Show();
        vertexIterator = vertexIterator->adjVertexNext;
        vertexNumber++;
    }

    /* debugging polygon for straight skeleton */
}

void generateStraightSkeleton(Polygon poly)
{
    // Stores segments for straight skeleton
    vector<Segment> SkeletonForConvexPolygon;

    // WHILE LAV.size > 3:
    // For all vertices of LAV:
    //      get angle bisector of current vertex
    //      get angle bisector of next vertex
    //      get intersection point
    //      get distance of point from incidentEdgeA (joins current to next)
    //      if distance is MIN:
    //          vMIN <- current vertex

    // coordinates[], i = 0
    // coordinates[i] <- vMIN.x, vMIN.y

    // add segment(currentVertex, vMIN) to Skeleton
    // add segment(nextVertex, vMIN) to Skeleton

    // remove current vertex from LAV
    // remove next vertex from LAV
    // add vMIN to LAV

    /* Modify LAV */
    // For all (v) vertices of LAV (except vMIN):
    //      v->Modify(l) (where, l = dist. from edge) -> Modify will just set x, y coords and vector's i, j and put 0 for all other vals

    // For all (v) vertices of LAV (except vMIN):
    //      if v equals vMIN             
    
    // For all (v) vertices of LAV:
    //      v->setAngleBisector();
}
