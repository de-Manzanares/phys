#include <iostream>
#include "Surface.h"

Surface::Surface(double depth, double area)
        :Point(depth)
{
    setArea(area);
}
void Surface::setArea(double area)
{
    if (area>=0) {
        A = area;
    }
    else {
        A = 0;
    }
}
double Surface::getArea() const
{
    return A;
}
void Surface::print() const
{
    Point::print();
    std::cout << "A   = " << getArea() << " mass^2"
              << std::endl;
}
