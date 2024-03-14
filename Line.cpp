#include "Line.hpp"

Line::Line()
{    
}

Line::Line(double xA, double yA, double xB, double yB)
{
    this->x_coeff = yB - yA;
    this->y_coeff = xB - xA;
    this->constant = this->x_coeff * xA + this->y_coeff * yB;  
}

Line::~Line()
{
}