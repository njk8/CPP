#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "Component.h"

class Capacitor : public Component
{
public:
    Capacitor(std::string name, Connection& left, Connection& right, double capacitance);
    ~Capacitor();
    
    void simulate(double const dt) override;
    double current() const override;

private:
    double capacitance{};
    double internal_charge{};
};

#endif