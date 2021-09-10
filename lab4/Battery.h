#ifndef BATTERY_H
#define BATTERY_H

#include "Component.h"

class Battery : public Component
{
public:
    Battery(std::string name, Connection& left, Connection& right, double volt);
    ~Battery();
    
    void simulate(double const dt) override;
    double current() const override;
    double voltage() const override;

private:
    double volt{};
};

#endif