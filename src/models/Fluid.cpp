#include "Fluid.h"
#include <iostream>

Fluid::Fluid()
{
    m = 0;
    V = 0;
    rho = 0;
}
Fluid::Fluid(double density)
{
    m = 0;
    V = 0;
    setDensity(density);
}
Fluid::Fluid(double mass, double volume, double density)
{
    if (density==-1) {
        setMass(mass);
        setVolume(volume);
        rho = m/V;
    }
    if (volume==-1) {
        setMass(mass);
        setDensity(density);
        V = m/rho;
    }
    if (mass==-1) {
        setVolume(volume);
        setDensity(density);
        m = rho*V;
    }
}
void Fluid::setMass(double mass)
{
    if (mass>=0) {
        m = mass;
    }
    else {
        m = 0;
    }
}
void Fluid::setVolume(double volume)
{
    if (volume>=0) {
        V = volume;
    }
    else {
        V = 0;
    }
}
void Fluid::setDensity(double density)
{
    if (density>=0) {
        rho = density;
    }
    else {
        rho = 0;
    }
}
double Fluid::getMass() const
{
    return m;
}
double Fluid::getVolume() const
{
    return V;
}
double Fluid::getDensity() const
{
    return rho;
}
void Fluid::print() const
{
    std::cout << "m   = " << m << " kg\n"
              << "V   = " << V << " m^3\n"
              << "rho = " << rho << " kg/m^3"
              << std::endl;
}
double Fluid::calculateAbsolutePressure(double depth) const
{
    return rho*9.80*depth;
}
double Fluid::calculateAbsolutePressure(double depth, double p0) const
{
    return p0+(rho*9.80*depth);
}
double Fluid::calculateBuoyantForce(double mass, double volume, double density) const
{
    double Fb;

    if (density==-1) {
        density = mass/volume;
    }
    else if (volume==-1) {
        volume = mass/density;
    }
    else if (mass==-1) {
        mass = density*volume;
    }

    if (density>rho) {
        Fb = volume*rho*9.80;
    }
    else {
        Fb = mass*9.80;
    }

    return Fb;
}
void Fluid::printAbsolutePressure(double depth) const
{
    std::cout << "p = " << calculateAbsolutePressure(depth) << " N/m^2" << std::endl;
}
void Fluid::printAbsolutePressure(double depth, double p0) const
{
    std::cout << "p = " << calculateAbsolutePressure(depth, p0) << " N/m^2" << std::endl;
}
void Fluid::printBuoyantForce(double mass, double volume, double density) const
{
    std::cout << "F_b = " << calculateBuoyantForce(mass, volume, density) << " N" << std::endl;
}
