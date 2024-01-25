#include "Fluid.h"
#include <iostream>

const double g = -9.80;

Fluid::Fluid()
{
    mass = 0;
    volume = 0;
    density = 0;
}
Fluid::Fluid(double density)
{
    mass = 0;
    volume = 0;
    setDensity(density);
}
Fluid::Fluid(double m, double v, double rho)
{
    if (rho==-1) {
        setMass(m);
        setVolume(v);
        setDensity(m/v);
    }
    else if (v==-1) {
        setMass(m);
        setDensity(rho);
        setVolume(m/rho);
    }
    else if (m==-1) {
        setVolume(v);
        setDensity(rho);
        setMass(rho*v);
    }
}
void Fluid::setMass(double m)
{
    if (m>=0) {
        mass = m;
    }
    else {
        mass = 0;
    }
}
void Fluid::setVolume(double v)
{
    if (v>=0) {
        volume = v;
    }
    else {
        volume = 0;
    }
}
void Fluid::setDensity(double rho)
{
    if (rho>=0) {
        density = rho;
    }
    else {
        density = 0;
    }
}
double Fluid::getMass() const
{
    return mass;
}
double Fluid::getVolume() const
{
    return volume;
}
double Fluid::getDensity() const
{
    return density;
}
void Fluid::print() const
{
    std::cout << "mass    = " << mass << " kg\n"
              << "volume  = " << volume << " mass^3\n"
              << "density = " << density << " kg/mass^3"
              << std::endl;
}
double Fluid::calculateAbsolutePressure(double depth) const
{
    return density*g*depth;
}
double Fluid::calculateAbsolutePressure(double depth, double p0) const
{
    return p0+(density*g*depth);
}
double Fluid::calculateBuoyantForce
        (double m, double v, double rho) const
{
    double Fb;

    if (rho==-1) {
        rho = m/v;
    }
    else if (v==-1) {
        v = m/rho;
    }
    else if (m==-1) {
        m = rho*v;
    }

    if (rho>rho) {
        Fb = v*rho*g;
    }
    else {
        Fb = m*g;
    }

    return Fb;
}
void Fluid::printAbsolutePressure(double depth) const
{
    std::cout << "p = " << calculateAbsolutePressure(depth) << " N/mass^2"
              << std::endl;
}
void Fluid::printAbsolutePressure(double depth, double p0) const
{
    std::cout << "p = " << calculateAbsolutePressure(depth, p0) << " N/mass^2"
              << std::endl;
}
void Fluid::printBuoyantForce(double m, double v, double rho) const
{
    std::cout << "F_b = " << calculateBuoyantForce(m, v, rho)
              << " N" << std::endl;
}
