#include "Circuit.h"

using namespace std;

Circuit::Circuit(std::initializer_list<Component*> list) 
{
    for (auto& element : list)
        circuit.push_back(element);
}

Circuit::~Circuit() 
{
    // since the circuit object is a vector of pointers, we delete each component to prevent memory leaks
    for (auto& element : circuit)
        delete element;
}

void Circuit::simulate(int const iterations, int const print, double const dt)
{
    int counter{};
    int print_at = iterations/print;

    // component names
    for (auto const& element : circuit)
        cout << setw(13) << element->get_name(); 
    cout << endl;

    // volt and current
    for (unsigned int i{0}; i < circuit.size(); i++)
        cout << setw(7) << "Volt" << setw(6) << "Curr"; 
    cout << endl;

    // update simulation of circuit
    cout << fixed << setprecision(2);
    while(counter < iterations)
    {
        for (auto const& element : circuit)
            element->simulate(dt);
        counter++;

        // print values
        if ((counter % print_at) == 0)
        {
            for (auto const& element : circuit)
                cout << setw(7) << element->voltage() << setw(6) << element->current();
            cout << endl;
        }
    }
}