#include <iostream>
#include "Point.h"

Point::Point(double depth)
{
    setDepth(depth);
}
void Point::setDepth(double depth)
{
    if (depth>=0) {
        h = depth;
    }
    else {
        h = 0;
    }
}
double Point::getDepth() const
{
    return h;
}
void Point::print() const
{
    std::cout << "h   = " << getDepth() << " m"
              << std::endl;
}
