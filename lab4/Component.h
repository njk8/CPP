#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Connection.h"

// Component is our base class, from which battery, resistor and capacitor are derived
class Component
{
public:
    Component(std::string name, Connection& left, Connection& right);   // base constructor
    virtual ~Component() = default;
    virtual void simulate(double const dt) = 0; // simulate charge transfer for duration of one time step
    virtual double current() const = 0; // get current of component
    virtual double voltage() const; // get voltage of component
    std::string get_name() const;   // get_name is the same for all components, hence not virtual
    
protected:   
    std::string name{};
    // left and right connections as references, so that their charge is actually changed when simulating the circuit
    Connection& left;
    Connection& right;
};

#endif