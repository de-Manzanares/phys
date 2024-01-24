cmake_minimum_required(VERSION 3.27)
project(phys)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        src/models
)

add_executable(phys src/main.cpp
        src/models/Fluid.cpp
        src/models/Point.cpp
        src/models/Surface.cpp
        src/models/Particle.cpp
        src/app/shmBuoyancy.cpp
)
