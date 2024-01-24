#ifndef PHYS_FLUID_H
#define PHYS_FLUID_H

class Fluid {
public:
    Fluid();
    Fluid(double density);
    Fluid(double mass, double volume, double density);
    void setMass(double mass);
    void setVolume(double volume);
    void setDensity(double density);
    double getMass() const;
    double getVolume() const;
    double getDensity() const;
    double calculateAbsolutePressure(double depth) const;
    double calculateAbsolutePressure(double depth, double p0) const;
    double calculateBuoyantForce(double mass, double volume, double density) const;
    void printAbsolutePressure(double depth) const;
    void printAbsolutePressure(double depth, double p0) const;
    void printBuoyantForce(double mass, double volume, double density) const;
    void print() const;

private:
    double m;
    double V;
    double rho;
};

#endif //PHYS_FLUID_H
