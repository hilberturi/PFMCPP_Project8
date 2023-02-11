#pragma once

#include <string>

struct Vehicle
{
    Vehicle(const std::string& n) : name(n) { }
    
    //Special member Functions.  See instruction 9) and note in main()
    virtual ~Vehicle() = default;
    Vehicle(const Vehicle&) = default;
    Vehicle& operator=(const Vehicle&) = default;
    
    virtual void setSpeed(int s);
    
    virtual void tryToEvade();

    friend struct HighwayPatrol;

protected:
    int speed = 0;
    std::string name;
};
