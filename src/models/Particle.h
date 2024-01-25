#include <vector>

#ifndef PHYS_PARTICLE_H
#define PHYS_PARTICLE_H

class Particle {
public:
    Particle();
    void setMass(double m);
    void updateMass();
    void setVolume(double v);
    void setDensity(double rho);
    void setPosition(double x0, double x1, double x2);
    void setVelocity(double v);
    void setAcceleration(double a);
    double getMass() const;
    double getVolume() const;
    double getDensity() const;
    std::vector<double> getPosition() const;
    double getVelocity() const;
    double getAcceleration() const;

private:
    double mass;
    double volume;
    double density;
    std::vector<double> position;
    double velocity;
    double acceleration;
};

#endif //PHYS_PARTICLE_H
