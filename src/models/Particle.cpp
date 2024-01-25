#include "Particle.h"

const double g = -9.80;

Particle::Particle()
{
    setDensity(0);
    setMass(0);
    setVolume(0);
    set_position(0, 0, 0);
    set_velocity(0);
    set_acceleration(0);
    position = {0, 0, 0};
}
void Particle::setMass(double m)
{
    if (m>=0) {
        mass = m;
    }
    else {
        mass = 0;
    }
}
void Particle::setVolume(double v)
{
    if (v>=0) {
        volume = v;
    }
    else {
        volume = 0;
    }
}
void Particle::setDensity(double rho)
{
    if (rho>=0) {
        density = rho;
    }
    else {
        density = 0;
    }
}
void Particle::set_position(double x1)
{
    position[0] = 0;
    position[1] = x1;
    position[2] = 0;
}
void Particle::set_position(double x0, double x1, double x2)
{
    position = {x0, x1, x2};
}
void Particle::set_velocity(double v)
{
    velocity = v;
}
void Particle::set_acceleration(double a)
{
    acceleration = a;
}
double Particle::getMass() const
{
    return mass;
}
double Particle::get_volume() const
{
    return volume;
}
double Particle::getDensity() const
{
    return density;
}
std::vector<double> Particle::getPosition() const
{
    return position;
}
double Particle::get_velocity() const
{
    return velocity;
}
double Particle::get_acceleration() const
{
    return acceleration;
}
