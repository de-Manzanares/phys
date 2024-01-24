#include <vector>

#ifndef PHYS_PARTICLE_H
#define PHYS_PARTICLE_H

class Particle {
public:
    explicit Particle(double m = 0, double vol = 0, double rho = 0,
            double x0 = 0, double x1 = 0, double x2 = 0, double vel = 0,
            double a = 0);
    void setMass(double m);
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
    double getForceGravity() const;
    void updateForceGravity();

private:
    double mass;
    double volume;
    double density;
    std::vector<double> position;
    double velocity;
    double acceleration;
    double forceGravity;
    double forceBuoyancy;
};

#endif //PHYS_PARTICLE_H
