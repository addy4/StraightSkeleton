#ifndef LINE_HPP
#define LINE_HPP

class Line
{
public:
    // Cartesian
    double x_coeff;
    double y_coeff;
    double constant;

    // Normalized
    double normalizedXcoeff;
    double normalizedYcoeff;
    double normalizedConstant;

    // Vectorial
    double icoeff;
    double jcoeff;

    Line();
    Line(double xA, double xB, double yA, double yB); // X1 Y1 X2 Y2
    ~Line();

    void reverseSign();
    void Show();
};

#endif //LINE_HPPP
