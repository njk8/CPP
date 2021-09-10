#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor : public Component
{
public:
    Resistor(std::string name, Connection& left, Connection& right, double resistance);
    ~Resistor();
    
    void simulate(double const dt) override;
    double current() const override;

private:
    double resistance{};
};

#endif