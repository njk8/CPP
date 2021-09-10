#include "Battery.h"

// Constructor is extended by volt value (how much to charge the battery)
Battery::Battery(std::string name, Connection& left, Connection& right, double volt)
    : Component(name, left, right), volt{volt} {}

Battery::~Battery() {}

void Battery::simulate(double const dt) 
{
    // we assume that left terminal is always the positive
    // battery never runs out --> always keeps voltage difference constant
    left.charge = volt;
    right.charge = 0.0; 
}

double Battery::current() const 
{
    // our idealized battery always has a current of 0
    return 0.0;
}

double Battery::voltage() const
{
    // override the component's voltage() function, so that our idealized battery
    // always returns the specified volt  value at end of simulation cycle (terminals 
    // might be updated by other components, but battery keeps charge constant)
    return volt;
}