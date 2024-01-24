#include <iostream>
#include "Fluid.h"
#include "Point.h"
#include "Surface.h"

int main()
{
    Fluid fluid1(1000);
    fluid1.print();
    fluid1.printAbsolutePressure(1);
    fluid1.printAbsolutePressure(1, 9800);
    fluid1.printAbsolutePressure(2);

    Fluid fluid2(1200);
    fluid2.printBuoyantForce(-1, 1, 1300);

    return 0;
}
