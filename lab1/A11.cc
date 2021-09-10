#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num{};
    double real{};
    char c{};
    string word{};
    
    cout << "Enter one integer: ";
    cin >> num;
    cout << "You entered the number: " << num << "\n" << endl;

    cin.ignore(1000, '\n');
    cout << "Enter four integers: ";
    cin >> num;
    cout << "You entered the numbers: " << num;
    cin >> num;
    cout << " " << num;
    cin >> num;
    cout<< " "<< num;
    cin >> num ;
    cout << " " << num << "\n" << endl;

    cin.ignore(1000, '\n');
    cout << "Enter one integer and one real number: ";
    cin >> num >> real;
    cout << "The real is: " << setw(11) << right << fixed << setprecision(3) << real << endl;
    cout << "The integer is: " << setw(8) << right << num << "\n" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Enter one real and one integer number: ";
    cin >> real >> num;
    cout << "The real is: " << setw(11) << right << setfill('.') << fixed << setprecision(3) << real << endl;
    cout << "The integer is: " << setw(8) << right << setfill('.') << num << "\n" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Enter a character: ";
    cin >> c;
    cout << "You entered: " << c << "\n" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Enter a word: ";
    cin >> word;
    cout << "The word '" << word << "' has "<< word.size() << " character(s). \n" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Enter an integer and a word: ";
    cin >> num >> word ;
    cout << "You entered ´"<< num << "´ and ´"<< word << "´. \n" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Enter an character and a word: ";
    cin >> c >> word ;
    cout << "You entered the string \""<< word << "\" and the character ´" << c << "´. \n" << endl;
    
    cin.ignore(1000, '\n');
    cout << "Enter a word and a real number: ";
    cin >> word >> real ;
    cout << "You entered \""<< word << "\" and \"" << real << "\". \n" << endl;

    cin.ignore(1000, '\n');
    cout << "Enter a text-line: ";
    getline(cin, word);
    cout << "You entered: \"" << word << "\" \n" << endl;

    cout << "Enter a second line of text: ";
    getline(cin, word);
    cout << "You entered: ´" << word << "\" \n" << endl;
 
    cout << "Enter three words: ";
    cin >> word;
    cout << "You entered: ´" << word << " ";
    cin >> word;
    cout << word << " ";
    cin >> word;
    cout << word << "´" << endl;
    
    return 0;
}