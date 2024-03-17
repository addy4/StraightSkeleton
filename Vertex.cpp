#include "Vertex.hpp"
#include "Line.hpp"
#include "Utils.hpp"
#include <iostream>
#include <math.h>
#include <cmath>

#define DEBUG 0

using namespace std;

Vertex::Vertex()
{
}

Vertex::Vertex(double x_coord, double y_coord)
{
    this->adjVertexPrev = nullptr;
    this->adjVertexNext = nullptr;
    this->x_coord = x_coord;
    this->y_coord = y_coord;
}

void Vertex::Info()
{
    #if DEBUG == 1
    cout << "########################################" << endl;
    
    // Current vertex
    cout << "At vertex... (" << this->x_coord << ", " << this->y_coord << ")" << endl;
    cout << endl;

    // Adjacent vertices
    cout << "Next vertex .... (" << this->adjVertexNext->x_coord << ", " << this->adjVertexNext->y_coord << ")" << endl;
    cout << "Previous vertex .... (" << this->adjVertexPrev->x_coord << ", " << this->adjVertexPrev->y_coord << ")" << endl;
    cout << endl;
    
    // Incident edges
    cout << "Incident edge A point to next -> " << endl;
    this->IncidentEdgeA.Show();
    cout << "Incident edge B point to prev -> " << endl;
    this->IncidentEdgeB.Show();
    cout << endl;

    // Angle bisector
    cout << "Angle bisector -> " << endl;
    this->angleBisector.Show();
    cout << endl;

    cout << "########################################" << endl;
    #endif
}

void Vertex::setIncidentEdges()
{
    // Equations for incident edges
    this->IncidentEdgeA = Line(this->x_coord, this->y_coord, adjVertexNext->x_coord, adjVertexNext->y_coord);
    this->IncidentEdgeB = Line(this->x_coord, this->y_coord, adjVertexPrev->x_coord, adjVertexPrev->y_coord);

    // Unit vector representation
    this->IncidentEdgeA.setUnitVector();
    this->IncidentEdgeB.setUnitVector();
}

void Vertex::computeAngleType()
{
    // Initially angle set to E
    this->angleType = 'E';

    // For determining whether angle at vertex is obtuse or acute or 90 using vector representation of Lines
    int costheta = Utils::dotProductSign(this->IncidentEdgeA, this->IncidentEdgeB);
    
    //cout << "cos theta -> " << costheta << endl;

    if(costheta > 0) {
        this->angleType = 'A';
    }
    else if(costheta < 0) {
        this->angleType = 'O';
    }

    // Otherwise, 90 degrees. Angle type is 'E'
}

void Vertex::setAngleBisector()
{
    this->computeAngleType();

    //cout << this->angleType << endl;

    Line bisector;

    if(this->angleType == 'E') {

        double desiredSlope = (this->IncidentEdgeA.unitVectorJcoeff + this->IncidentEdgeB.unitVectorJcoeff)/(this->IncidentEdgeA.unitVectorIcoeff + this->IncidentEdgeB.unitVectorIcoeff);
        
        double actualSlope;
        actualSlope = -(this->IncidentEdgeA.normalizedXcoeff - this->IncidentEdgeB.normalizedXcoeff)/(this->IncidentEdgeA.normalizedYcoeff - this->IncidentEdgeB.normalizedYcoeff);
        if(actualSlope * desiredSlope > 0) {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff - this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff - this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant - this->IncidentEdgeB.normalizedConstant;
        }
        else {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff + this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff + this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant + this->IncidentEdgeB.normalizedConstant; 
        }
        this->angleBisector = bisector;
        return;
    }

    if(this->IncidentEdgeA.constant * this->IncidentEdgeB.constant < 0) {
        IncidentEdgeB.reverseSign();
    }

    //this->IncidentEdgeA.ShowNormalized();
    //this->IncidentEdgeB.ShowNormalized();

    if((this->IncidentEdgeA.x_coeff * this->IncidentEdgeB.x_coeff + this->IncidentEdgeA.y_coeff * this->IncidentEdgeB.y_coeff) < 0) {
        if(this->angleType == 'A') {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff - this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff - this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant - this->IncidentEdgeB.normalizedConstant;
        }
        else if(this->angleType == 'O') {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff + this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff + this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant + this->IncidentEdgeB.normalizedConstant;
        }
    }
    else {
        if(this->angleType = 'A') {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff + this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff + this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant + this->IncidentEdgeB.normalizedConstant;
        }
        else if(this->angleType = 'O') {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff - this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff - this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant - this->IncidentEdgeB.normalizedConstant;
        }
    }

    this->angleBisector = bisector;
    return;
}

// Modify vertex XY coordinates based on the distance moved by edge
void Vertex::modifyCoordinates(double d)
{
    // Get angle between angle bisector and incident edge A (vertex -> nextVertex)
    double angleDegrees = abs(Utils::angleBwLines(this->angleBisector, this->IncidentEdgeA));

    if(angleDegrees > 90) {
        angleDegrees = 180.0 - angleDegrees;
    }

    double angleRadians = angleDegrees * 3.1415 / 180.0;

    // Distance to move along angle bisector
    double lDistance = d / sin(angleRadians);

    // Angle b/w angle bisector and X-axis (take acute angle only)
    double bisectorAngleDegrees = abs(Utils::angleBwLines(this->angleBisector, Line(0, 0, 1, 0)));

    if(bisectorAngleDegrees > 90) {
        bisectorAngleDegrees = 180.0 - bisectorAngleDegrees;
    }

    double bisectorAngleRadians = bisectorAngleDegrees * 3.1415 / 180.0; 

    //this->IncidentEdgeA.Show();
    //this->IncidentEdgeB.Show();

    // Get vertex movement directions
    pair<double, double> vectorResultant = Utils::vectorSum(this->IncidentEdgeB, this->IncidentEdgeA);


    double xdirection;
    double ydirection;
    
    if(abs(vectorResultant.first) == 0) 
    {
        xdirection = 0;
    }
    else
    {
        xdirection = vectorResultant.first/abs(vectorResultant.first);
    }

    if(abs(vectorResultant.second) == 0)
    {
        ydirection = 0;
    }
    else
    {
        ydirection = vectorResultant.second/abs(vectorResultant.second);
    }
    
    //cout << "xdir: " << xdirection << ", ydir: " << ydirection << endl;
    //cout << "ldistance: " << lDistance << endl;
    //cout << "cos theta: " << cos(bisectorAngleRadians) << endl;

    this->x_coord = this->x_coord + xdirection * lDistance * cos(bisectorAngleRadians);
    this->y_coord = this->y_coord + ydirection * lDistance * sin(bisectorAngleRadians);
}

Vertex::~Vertex()
{
}