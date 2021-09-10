#include "Capacitor.h"

// Constructor is extended by capacitance value; also initilize internal charge storage to 0
Capacitor::Capacitor(std::string name, Connection& left, Connection& right, double capacitance)
    : Component(name, left, right), capacitance(capacitance), internal_charge(0.0) {}

Capacitor::~Capacitor() {}

void Capacitor::simulate(double const dt)
{
    // calculate how much charge to be stored internally and moved between terminals as follows:
    // charge = capacitance * (potential difference * internally stored charge) * time step
    double move_charge = capacitance * (voltage() - internal_charge) * dt;

    // move charge from fuller to emptier terminal (check which one has higher charge)
    // also add charge to internal charge storage
    if (left.charge > right.charge)
    {
        left.charge -= move_charge;
        right.charge += move_charge;
        internal_charge += move_charge;
    }
    else if (left.charge < right.charge)
    {
        left.charge += move_charge;
        right.charge -= move_charge;
        internal_charge += move_charge;
    }
}

double Capacitor::current() const 
{
    // current = C(V-L)
    return capacitance * (voltage() - internal_charge);
}