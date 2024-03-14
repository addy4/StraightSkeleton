#include "Vertex.hpp"
#include "Line.hpp"
#include "Utils.hpp"
#include <iostream>

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

    cout << "Edge B" << endl;
    this->IncidentEdgeB.Show();

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
}

void Vertex::setAngleBisector()
{
    this->computeAngleType();

    if(this->angleType == 'E') {
        return;
    }

    Line bisector;

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
            bisector.x_coeff = this->IncidentEdgeA.normalizedXcoeff + this->IncidentEdgeB.normalizedXcoeff;
            bisector.y_coeff = this->IncidentEdgeA.normalizedYcoeff + this->IncidentEdgeB.normalizedYcoeff;
            bisector.constant = this->IncidentEdgeA.normalizedConstant + this->IncidentEdgeB.normalizedConstant;
        }
    }

    this->angleBisector = bisector;

    return;
}