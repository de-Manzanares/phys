#include <iostream>
#include "StandingWavesOnAString.h"

int main()
{
    StandingWavesOnAString sim;

    sim.list_node_properties_massless(15);
    sim.list_node_properties_fixed_linear_density(15);

    return 0;
}
