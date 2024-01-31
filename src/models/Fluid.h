#ifndef PHYS_FLUID_H
#define PHYS_FLUID_H

class Fluid {
public:
    Fluid();
    explicit Fluid(double density);
    Fluid(double m, double v, double rho);
    void setMass(double mass);
    void setVolume(double v);
    void setDensity(double density);
    double getMass() const;
    double getVolume() const;
    double get_density() const;
    double calculateAbsolutePressure(double depth) const;
    double calculateAbsolutePressure(double depth, double p0) const;
    double calculateBuoyantForce(double m, double v, double rho) const;
    double pressure_at_depth_h(double referencePressure, double h) const;

private:
    double mass;
    double volume;
    double density;
};

#endif //PHYS_FLUID_H
