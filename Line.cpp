#include "Line.hpp"
#include <cmath>

Line::Line()
{    
}

Line::Line(double xA, double yA, double xB, double yB)
{
    // Cartesian
    this->x_coeff = yB - yA; //  ax
    this->y_coeff = xB - xA; //  by
    this->constant = -(this->x_coeff * xA + this->y_coeff * yA); //  c

    // Vectorial
    this->icoeff = xB - xA;
    this->jcoeff = yB - yA;

    // Denominator
    double denom = sqrt(this->x_coeff * this->x_coeff + this->y_coeff * this->y_coeff);

    // Normalized
    this->normalizedXcoeff = this->x_coeff/denom;
    this->normalizedYcoeff = this->y_coeff/denom;
    this->constant = this->constant/denom;  
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