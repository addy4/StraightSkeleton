#include "Utils.hpp"
#include "Line.hpp"
#include "Vertex.hpp"

int Utils::dotProductSign(Line incident1, Line incident2)
{
    if((incident1.icoeff * incident2.icoeff + incident1.jcoeff * incident2.jcoeff) > 0) {
        return +1;
    }
    else if((incident1.icoeff * incident2.icoeff + incident1.jcoeff * incident2.jcoeff) < 0) {
        return -1;
    }
    return 0;
}