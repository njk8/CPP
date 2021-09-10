#include "Resistor.h"

// Constructor is extended by resistance value
Resistor::Resistor(std::string name, Connection& left, Connection& right, double resistance)
    : Component(name, left, right), resistance{resistance} {}

Resistor::~Resistor() {}

void Resistor::simulate(double const dt)
{
    // calculate how much charge to be moved between terminals as follows:
    // charge = potential difference / resistance * time step
    double move_charge = dt * voltage() / resistance;
    
    // move charge from fuller to emptier terminal (check which one has higher charge)
    if (left.charge > right.charge)
    {
        left.charge -= move_charge;
        right.charge += move_charge;
    } 
    else if (left.charge < right.charge)
    {
        left.charge += move_charge;
        right.charge -= move_charge;
    }
}

double Resistor::current() const 
{
    return voltage()/resistance;
}
