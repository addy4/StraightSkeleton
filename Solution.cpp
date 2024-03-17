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

#define DEBUG 1
#define SKEL 1
#define SIMULATE 0

#include "Line.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"
#include "Utils.hpp"

using namespace std;

typedef vector<pair<double,double>> waveFront;

void showCurrentWavefront(Polygon poly);
void AlgoGenerateStraightSkeleton(Polygon poly);
void moveVertices(double d, Polygon* polyPtr);
void generateStraightSkeleton(Polygon* polyPtr);

int main(int argc, char const *argv[])
{
    // Input vertices
    // vector<pair<int,int>> network = {make_pair(1, 5), make_pair(4, 1), make_pair(8, 3), make_pair(7, 7), make_pair(3, 9)};
    // vector<pair<int,int>> networke = {make_pair(4, 1), make_pair(8, 3), make_pair(7, 7), make_pair(3, 9)};
    // vector<pair<int,int>> network = {make_pair(1, 5), make_pair(4, 1), make_pair(8, 3), make_pair(7, 7)};
    // vector<pair<int,int>> network = {make_pair(1, 5), make_pair(4, 1), make_pair(6, 3), make_pair(7, 7)};
    // vector<pair<int,int>> network = {make_pair(1, 4), make_pair(6, 1), make_pair(12, 4), make_pair(6, 18)};
    // vector<pair<int,int>> network = {make_pair(4, 9), make_pair(0, 2), make_pair(17, 10), make_pair(15, 15)};
    // vector<pair<int,int>> network = {make_pair(4, 9), make_pair(0, 2), make_pair(30, 12), make_pair(27, 19), make_pair(24, 19)};
    vector<pair<int,int>> network = {make_pair(4, 9), make_pair(2,2), make_pair(30, 12), make_pair(32,19), make_pair(22, 29), make_pair(17, 27), make_pair(14, 24)};
    waveFront wave;
    
    // Creating polygon
    int vertexNumber = 0;
    Polygon poly;

    Vertex* prev;
    Vertex* head = new Vertex(network[vertexNumber].first, network[vertexNumber].second);
    prev = head;
    
    poly.addVertex(head);
    wave.push_back(network[vertexNumber]);
    vertexNumber++;

    while (vertexNumber < network.size())
    {
        wave.push_back(network[vertexNumber]);
        Vertex* currVertex = new Vertex(network[vertexNumber].first, network[vertexNumber].second); 
        poly.addVertex(currVertex);
        prev = currVertex;
        vertexNumber++;  
    }

    #if SIMULATE == 1
    /* Simulation of straight skeleton demonstrating shrinking polygon */

    // Utils::printWaveFront(wave);
    Utils::printPolygon(wave);
    showCurrentWavefront(poly);

    moveVertices(0.4, &poly);
    showCurrentWavefront(poly);

    moveVertices(0.4, &poly);
    showCurrentWavefront(poly);

    moveVertices(0.4, &poly);
    showCurrentWavefront(poly);

    /* Simulation of straight skeleton demonstrating shrinking polygon */
    #endif

    #if SKEL == 1
    Utils::printPolygon(wave);
    generateStraightSkeleton(&poly);
    //generateStraightSkeleton(&poly);
    #endif
    
    return 0;
}

void moveVertices(double d, Polygon* polyPtr)
{
    waveFront wave;
    pair<double,double> pointMovement;

    Vertex* vertexIterator = polyPtr->LAV.head;
    int vertexNumber = 0;
    while (vertexNumber < polyPtr->LAV.size)
    {
        vertexIterator->modifyCoordinates(d);
        //cout << "Modified.. " << vertexIterator->x_coord << ", " << vertexIterator->y_coord << endl;
        pointMovement = make_pair(vertexIterator->x_coord, vertexIterator->y_coord);
        wave.push_back(pointMovement);
        vertexIterator = vertexIterator->adjVertexNext;
        vertexNumber++;
    }

    //Utils::printWaveFront(wave);
    Utils::printPolygon(wave);

    vertexIterator = polyPtr->LAV.head;
    vertexNumber = 0;
    pair<double,double> FinalPoints;
    while (vertexNumber < polyPtr->LAV.size)
    {
        vertexIterator->setIncidentEdges();
        vertexIterator = vertexIterator->adjVertexNext;
        vertexNumber++;
    }
    
}

void showCurrentWavefront(Polygon poly)
{
    /* debugging polygon for straight skeleton */

    Vertex* vertexIterator = poly.LAV.head;
    int vertexNumber = 0;
    while (vertexNumber < poly.LAV.size)
    {
        vertexIterator->setIncidentEdges();
        vertexIterator->setAngleBisector();
        vertexIterator->Info();
        vertexIterator = vertexIterator->adjVertexNext;
        vertexNumber++;
    }

    /* debugging polygon for straight skeleton */
}

void AlgoGenerateStraightSkeleton(Polygon poly)
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

void generateStraightSkeleton(Polygon* polyPtr)
{
    vector<Segment> StraightSkeletonForPolygon;

    /*
    // If LAV.size <= 3, polygon collapses at next iteration
    Vertex* currVertex = polyPtr->LAV.head;
    Vertex* nextVertex;
    double edgeDistance = INT16_MAX;

    int VertexNumber = 0;

    while (VertexNumber < polyPtr->LAV.size)
    {
        currVertex->setIncidentEdges();
        currVertex->setAngleBisector();
        Line currAngleBisector = currVertex->angleBisector;
        
        nextVertex = currVertex->adjVertexNext;
        nextVertex->setIncidentEdges();
        nextVertex->setAngleBisector();
        Line nextAngleBisector = nextVertex->angleBisector;
        
        pair<double,double> Intersection = Utils::IntersectionPoint(currAngleBisector, nextAngleBisector);
        double distanceFromEdge = Utils::distanceFromLine(Intersection, currVertex->IncidentEdgeA);
        if(distanceFromEdge < edgeDistance) {
            edgeDistance = distanceFromEdge;
        }
        currVertex = currVertex->adjVertexNext;
        VertexNumber++;
    }

    moveVertices(edgeDistance, polyPtr);
    */

    // If LAV.size <= 3, polygon collapses at next iteration
    Vertex* currVertex = polyPtr->LAV.head;
    Vertex* nextVertex;
    double edgeDistance = INT16_MAX;

    while (polyPtr->LAV.size > 3)
    {

        //cout << "Number of vertices... " << polyPtr->LAV.size << endl;

        int VertexNumber = 0;
        while (VertexNumber < polyPtr->LAV.size)
        {
            currVertex->setIncidentEdges();
            currVertex->setAngleBisector();
            Line currAngleBisector = currVertex->angleBisector;
        
            nextVertex = currVertex->adjVertexNext;
            nextVertex->setIncidentEdges();
            nextVertex->setAngleBisector();
            Line nextAngleBisector = nextVertex->angleBisector;
        
            pair<double,double> Intersection = Utils::IntersectionPoint(currAngleBisector, nextAngleBisector);
            double distanceFromEdge = Utils::distanceFromLine(Intersection, currVertex->IncidentEdgeA);
            if(distanceFromEdge < edgeDistance) {
                edgeDistance = distanceFromEdge;
            }
            currVertex = currVertex->adjVertexNext;
            VertexNumber++;
        }

        // Move vertices
        moveVertices(edgeDistance, polyPtr);

        // Remove coincing vertices
        VertexNumber = 0;
        currVertex = polyPtr->LAV.head;
        while (VertexNumber < polyPtr->LAV.size)
        {
            nextVertex = currVertex->adjVertexNext;
            if(Utils::coincide(*currVertex, *nextVertex)) {
                polyPtr->removeVertex(currVertex);
            }
            currVertex = currVertex->adjVertexNext;
            VertexNumber++;
        }   
    }
}
