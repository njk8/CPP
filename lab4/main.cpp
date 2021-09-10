#include <iostream>
#include <iomanip>
#include <vector>

#include "Battery.h"
#include "Capacitor.h"
#include "Circuit.h"
#include "Connection.h"
#include "Resistor.h"
#include "Component.h"

using namespace std;

int main(int argc, char* argv[])
{
    // storing command line arguments
    vector<string> args{argv, argv + argc};

    int iterations{};
    int print_lines{};
    double time_step{};
    double battery_voltage{};

    // check that all required arguments are passed via command line
    if (args.size() < 5)
    {
        cerr << "Not enough arguments passed!" << endl;
        return 0;
    } else if (args.size() > 5) {
        cerr << "Too many arguments passed!" << endl;
        return 0;
    }
    
    // catch error if string to int/double conversion does not work (e.g. a word was entered)
    try
    {
        iterations = stoi(args.at(1));
        print_lines = stoi(args.at(2));
        time_step = stod(args.at(3));
        battery_voltage = stod(args.at(4));
    }
    catch(const exception& e)
    {
        cerr << "Value you entered is not valid (should be: int int double double)" << endl;
        return 0;
    }

    // check that nr. of iterations is equal or greater than nr. of lines to print
    if (print_lines > iterations)
    {
        cerr << "Cannot print more lines than there are iterations" << endl;
        return 0;
    }
    
    // creating the 3 example circuits from the assignment
    Connection P{};
    Connection N{};
    Connection R124{};
    Connection R23{};
    Circuit net1{new Battery("Bat", P, N, battery_voltage),
                new Resistor("R1", P, R124, 6.0), 
                new Resistor("R2", R124, R23, 4.0),
                new Resistor("R3", R23, N, 8.0), 
                new Resistor("R4", R124, N, 12.0)};
    net1.simulate(iterations, print_lines, time_step);

    std::cout << std::endl;

    Connection L{};
    Connection R{};
    P.charge = 0.0; 
    N.charge = 0.0;
    Circuit net2{new Battery("Bat", P, N, battery_voltage),
                new Resistor("R1", P, L, 150.0),
                new Resistor("R2", P, R, 50.0),
                new Resistor("R3", L, R, 100.0),
                new Resistor("R4", L, N, 300.0),
                new Resistor("R5", R, N, 250.0)};
    net2.simulate(iterations, print_lines, time_step);

    std::cout << std::endl;

    P.charge = 0.0; 
    L.charge = 0.0;
    R.charge = 0.0;
    N.charge = 0.0;
    Circuit net3{new Battery("Bat", P, N, battery_voltage),
                new Resistor("R1", P, L, 150.0),
                new Resistor("R2", P, R, 50.0),
                new Capacitor("C3", L, R, 1.0),
                new Resistor("R4", L, N, 300.0),
                new Capacitor("C5", R, N, 0.75)};
    net3.simulate(iterations, print_lines, time_step);
}