#ifndef PHYS_SURFACE_H
#define PHYS_SURFACE_H

#include "Point.h"

class Surface : public Point {
public:
    Surface(double = 0, double = 0);
    void setArea(double);
    double getArea() const;
    void print() const;
private:
    double A;
};

#endif //PHYS_SURFACE_H
