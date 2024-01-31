cmake_minimum_required(VERSION 3.27)
project(phys)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        src/models
        src/models/equations
)

add_executable(phys src/main.cpp
        src/models/Fluid.cpp
        src/models/Particle.cpp
        src/app/shmBuoyancy.cpp
        src/models/FluidContainer.cpp
        src/models/StandingWavesOnAString.cpp
        src/models/StandingWavesOnAString.h
)
