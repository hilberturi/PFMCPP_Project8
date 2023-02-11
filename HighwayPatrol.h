#pragma once 

#include "Vehicle.h"

struct Highway;

struct HighwayPatrol : Vehicle 
{
    HighwayPatrol();

    //Special member Functions.  See instruction 9) and note in main()
    ~HighwayPatrol() override;
    HighwayPatrol(const HighwayPatrol&) = default;
    HighwayPatrol& operator=(const HighwayPatrol&) = default;

    void scanHighway(Highway* h);

    void pullOver( Vehicle* v, bool willArrest, Highway* h );
};
