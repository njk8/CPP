#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <initializer_list>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Component.h"

class Circuit
{
public:
    // use this initializer list constructor, so that any number of components can be passed when creating a circuit
    Circuit(std::initializer_list<Component*> list);
    ~Circuit();
    void simulate(int const iterations, int const print, double const dt);

private:
    std::vector<Component*> circuit;
};

#endif