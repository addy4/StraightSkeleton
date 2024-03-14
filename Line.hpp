#ifndef LINE_HPP
#define LINE_HPP

class Line
{
public:
    double x_coeff;
    double y_coeff;
    double constant;

    Line();
    Line(double xA, double xB, double yA, double yB);
    ~Line();
};

#endif //LINE_HPPP
