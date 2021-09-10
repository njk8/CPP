#include <iostream>
#include <iomanip>
using namespace std;

//TODO: Complementary work needed, 1-1: Only declare one variable on
//each line.

//TODO: Complementary work needed, 8-8: In this lab you are supposed
//to use manipulators from the library iomanip when you want to output
//characters.

//TODO: Complementary work needed, 2-2: Use an empty line to separate
//two logically different parts in the code to increase readability.

//TODO: Complementary work needed, 1-15: Use cerr for error output

//TODO: Complementary work needed, 4-3: Do not repeat sticky
//manipulators with permanent effect. Keep in mind, iterating sticky
//manipulators is considered repeating.

int main()
{
    float first_p{};
    float last_p{};
    float stride{};
    float tax_per{}; 

    cout << "INPUT PART" << endl;
    cout << setw(10) << setfill('=') << "" << endl;

    cout << setw(17) << setfill (' ') << left;
    cout << "Enter first price" << ": ";
    cin >> first_p;
    while(first_p < 0)
    {
        cerr << "ERROR: First price must be at least 0 (zero) SEK" << endl;
        cout << setw(17) << "Enter first price" << ": ";
        cin >> first_p;        
    }

    cout << setw(17) << "Enter last price" << ": ";
    cin >> last_p;
    while(last_p < 0 || last_p < first_p)
    {
        cerr << "ERROR: Last price must be at least 0 (zero) SEK and bigger than first price" << endl;
        cout << setw(17) << "Enter last price" << ": ";
        cin >> last_p;        
    }

    cout << setw(17) << "Enter stride" << ": ";
    cin >> stride;
    while(stride < 0.01)
    {
        cerr << "ERROR: Stride must be at least 0.01 SEK" << endl;
        cout << setw(17) << "Enter stride" << ": ";
        cin >> stride;        
    }
    
    cout << setw(17) << "Enter tax percent" << ": ";
    cin >> tax_per;
    while(tax_per < 0)
    {
        cerr << "ERROR: Tax percent must be at least 0 (zero) percent" << endl;
        cout << setw(17) << "Enter tax percent" << ": ";
        cin >> tax_per;        
    }

    cout << "\nTAX TABLE" << endl;
    cout << setw(9) << setfill('=') << "" << endl;
    
    cout << right << setfill(' ') << setw(15) << "Price" << setw(15) << "Tax" << setw(20) << "Price with tax" << endl;
    cout << setfill('-') << setw(15+15+20) << "" << endl;

    float price{first_p};
    float tax{};
    float price_w_t{};
    cout << fixed << setprecision(2) << setfill(' ');
    while(price < (last_p + stride))
    {
        tax = tax_per / 100 * price;
        price_w_t = price + tax;
        cout << setw(15) << price << setw(15) << tax << setw(20) << price_w_t << endl;
        price += stride;
    }

    return 0;
}