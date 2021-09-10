#include "Component.h"

Component::Component(std::string name, Connection& left, Connection& right)
    : name{name}, left{left}, right{right} {}

double Component::voltage() const
{
    // voltage = difference between each terminal
    return std::abs(left.charge - right.charge);
}

std::string Component::get_name() const
{
    return name;
}

/* pure virutal functions that dont need implementation:
 * virtual ~Component() = default;
 * virtual void simulate(double const dt) = 0;
 * virtual double current() const = 0;
 */