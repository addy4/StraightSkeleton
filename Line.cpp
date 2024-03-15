#include "Line.hpp"
#include <cmath>
#include <iostream>

using namespace std;

Line::Line()
{
    this->x_coeff = 0;
    this->y_coeff = 0;
    this->constant = 0;
    this->normalizedXcoeff = 0;
    this->normalizedYcoeff = 0;
    this->normalizedConstant = 0;
}

// Line from A to B
Line::Line(double xA, double yA, double xB, double yB)
{
    // Cartesian
    this->x_coeff = yB - yA; //  ax
    this->y_coeff = xA - xB; //  by
    this->constant = -(this->x_coeff * xA + this->y_coeff * yA); //  c

    // Vectorial
    this->icoeff = xB - xA;
    this->jcoeff = yB - yA;

    // Denominator
    double denom = sqrt(this->x_coeff * this->x_coeff + this->y_coeff * this->y_coeff);

    // Normalized
    this->normalizedXcoeff = this->x_coeff/denom;
    this->normalizedYcoeff = this->y_coeff/denom;
    this->normalizedConstant = this->constant/denom;  
}

Line::~Line()
{
}

void Line::reverseSign()
{
    this->x_coeff = -1 * this->x_coeff;
    this->y_coeff = -1 * this->y_coeff;
    this->constant = -1 * this->constant;
}

void Line::Show()
{
    cout << "A: " << x_coeff << endl;
    cout << "B: " << y_coeff << endl;
    cout << "C: " << constant << endl;
}

void Line::ShowNormalized()
{
    cout << "Denom: " << sqrt(this->x_coeff * this->x_coeff + this->y_coeff * this->y_coeff) << endl;
    cout << "AN: " << normalizedXcoeff << endl;
    cout << "BN: " << normalizedYcoeff << endl;
    cout << "CN: " << normalizedConstant << endl; 
}