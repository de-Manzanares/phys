#ifndef PHYS_POINT_H
#define PHYS_POINT_H

#include "Fluid.h"

class Point {
public:
    Point(double = 0);
    void setDepth(double);
    double getDepth() const;
    void print() const;
private:
    double h;
};

#endif //PHYS_POINT_H
