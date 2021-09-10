#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    string file{"test.txt"};
    /*cout << "Enter name of the file that should be read: "; 
    cin >> file;*/
    cout << "Analyzing the file \"" << file << "\"..." << endl;
    ifstream ifs{file};
    string s{}, min_word{}, max_word{};
    int word_count{0}, temp_len{}, min_len{INT_MAX}, max_len{0};
    double avg_len{0.00};
    
    while (ifs >> s)
    {
        // file is being read word by word   
        word_count++;
        // check if any letter of the word is a punctuation letter, e.g. dot, comma, question/exclamation mark, etc.
        for (char letter : s) {
            if (ispunct(letter)) s.erase(s.find(letter));
        }
        temp_len = s.size();
        if (temp_len < min_len) {
            min_len = temp_len;
            min_word = s;
        } 
        if (temp_len > max_len) {
            max_len = temp_len;
            max_word = s;
        }
        avg_len += temp_len;
    }

    if (word_count == 0)
    {
        cout << "Warning! File is empty, could not read any data." << endl;   
    } else {
        cout << "There are " << word_count << " words in the file." << endl;
        cout << "The shortest word was \"" << min_word << "\" with " << min_len << " character(s)." << endl;
        cout << "The longest word was \"" << max_word << "\" with " << max_len << " character(s)." << endl;
        cout << "The average length was " << fixed << setprecision(2) << avg_len/word_count << " character(s)." << endl;
    } 

    return 0;
}