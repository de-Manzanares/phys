#ifndef PHYS_STANDINGWAVESONASTRING_H
#define PHYS_STANDINGWAVESONASTRING_H

class StandingWavesOnAString {
public:
    void list_node_properties_massless(int nodes);
    void list_node_properties_fixed_linear_density(int nodes);
private:
    double harmonic;
    double linearDensity = 0.000295;
    double massOnPulley;
    double stringLength = 1.2;
    double stringMass;
    double const vibratorFrequency = 120;
    double wavelength;
    double waveSpeed;
};

#endif //PHYS_STANDINGWAVESONASTRING_H
