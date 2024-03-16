#include "Vertex.hpp"
#include "Line.hpp"
#include "Utils.hpp"
#include <iostream>
#include <math.h>
#include <cmath>

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

Vertex::~Vertex()
{
}

void Vertex::Info()
{
    cout << "   XY: " << this->x_coord << ", " << this->y_coord << endl;
    if(adjVertexPrev) {
        cout << "   Previous XY: " << adjVertexPrev->x_coord << ", " << adjVertexPrev->y_coord << endl;
    }
    if(adjVertexNext) {
        cout << "   Next XY: " << adjVertexNext->x_coord << ", " << adjVertexNext->y_coord << endl;
    }
}

void Vertex::computeAngleType()
{
    this->angleType = 'E';
    this->IncidentEdgeA = Line(this->x_coord, this->y_coord, adjVertexNext->x_coord, adjVertexNext->y_coord);
    this->IncidentEdgeB = Line(this->x_coord, this->y_coord, adjVertexPrev->x_coord, adjVertexPrev->y_coord);

    cout << "Edge A" << endl;
    this->IncidentEdgeA.Show();
    this->IncidentEdgeA.ShowNormalized();

    cout << "Edge B" << endl;
    this->IncidentEdgeB.Show();
    this->IncidentEdgeB.ShowNormalized();

    int costheta = Utils::dotProductSign(this->IncidentEdgeA, this->IncidentEdgeB);
    if(costheta > 0) {
        this->angleType = 'A';
    }
    else if(costheta < 0) {
        this->angleType = 'O';
    }
    else {
        cout << "90 degrees!!!!!!!" << endl;
    }
    cout << "Angle = " << this->angleType << endl;
}

void Vertex::setAngleBisector()
{
    this->computeAngleType();

    Line bisector;

    if(this->angleType == 'E') {
        double desiredSlope = (this->IncidentEdgeA.jcoeff + this->IncidentEdgeB.jcoeff)/(this->IncidentEdgeA.icoeff + this->IncidentEdgeB.icoeff);
        double actualSlope;
        actualSlope = -(this->IncidentEdgeA.normalizedXcoeff - this->IncidentEdgeB.normalizedXcoeff)/(this->IncidentEdgeA.normalizedYcoeff - this->IncidentEdgeB.normalizedYcoeff);
        if(actualSlope == desiredSlope) {
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

    if((this->IncidentEdgeA.x_coeff * this->IncidentEdgeB.x_coeff + this->IncidentEdgeA.y_coeff * this->IncidentEdgeB.y_coeff) < 0) {
        if(this->angleType == 'A') {
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff - this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff - this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant - this->IncidentEdgeB.normalizedConstant;
        }
        else if(this->angleType == 'O') {
            this->IncidentEdgeA.ShowNormalized();
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
    
    this->x_coord = this->x_coord + xdirection * lDistance * cos(bisectorAngleRadians);
    this->y_coord = this->y_coord + ydirection * lDistance * sin(bisectorAngleRadians);
}