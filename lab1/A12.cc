#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float first_p{}, last_p{}, stride{}, tax_per{};
    cout << "INPUT PART" << endl;
    cout << "==========" << endl;
    cout << "Enter first price: ";
    cin >> first_p;
    while(first_p < 0)
    {
        cout << "ERROR: First price must be at least 0 (zero) SEK" << endl;
        cout << "Enter first price: ";
        cin >> first_p;        
    }
    cout << "Enter last price : ";
    cin >> last_p;
    while(last_p < 0 || last_p < first_p)
    {
        cout << "ERROR: Last price must be at least 0 (zero) SEK and bigger than first price" << endl;
        cout << "Enter last price : ";
        cin >> last_p;        
    }
    cout << "Enter stride     : ";
    cin >> stride;
    while(stride < 0.01)
    {
        cout << "ERROR: Stride must be at least 0.01 SEK" << endl;
        cout << "Enter stride     : ";
        cin >> stride;        
    }    
    cout << "Enter tax percent: ";
    cin >> tax_per;
    while(tax_per < 0)
    {
        cout << "ERROR: Tax percent must be at least 0 (zero) percent" << endl;
        cout << "Enter tax percent: ";
        cin >> tax_per;        
    }

    cout << "\nTAX TABLE" << endl;
    cout << "=========" << endl;
    cout << setw(15) << "Price" << setw(15) << "Tax" << setw(20) << "Price with tax" << endl;
    cout << "--------------------------------------------------" << endl;

    float price{first_p}, tax{}, price_w_t{};
    while(price < (last_p + stride))
    {
        tax = tax_per / 100 * price;
        price_w_t = price + tax;
        cout << fixed << setprecision(2);
        cout << setw(15) << price << setw(15) << tax << setw(20) << price_w_t << endl;
        price += stride;
    }

    return 0;
}