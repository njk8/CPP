#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

bool remove_junk(string& word);
bool valid_word(string& word);

int main(int argc, char* argv[])
{
    // argc = number of arguments passed to the program
    // argv = a pointer to an array of pointers to C-strings,
    //        we can access the i:th argument with argv[i]
    if (argc == 1)
    {
        cerr << "Error: No arguments given.\nUsage: a.out FILE [-a] [-f] [-o N]" << endl;
        return 0;
    } else if (argc == 2) {
        cerr << "Error: Second argument missing or invalid.\nUsage: a.out FILE [-a] [-f] [-o N]" << endl;
        return 0;
    } else 
    {
        ifstream file{argv[1]};
        if (!file)
        {
            cerr << "Error: Could not open file." << endl;
            return 0;
        }
        // file and nr. of arguments seem fine; read the contents:
        vector<string> valid_words{};
        vector<string> potential_words{};
        map<string, int> word_map{};

        istream_iterator<string> iis{file};
        istream_iterator<string> eos{};
        vector<string> temp{iis, eos};

        // remove the junk at end and beginning of words
        copy_if(begin(temp), end(temp), back_inserter(potential_words), remove_junk);
        
        // check if words are valid and only copy the valid words into final words vector
        copy_if(begin(potential_words), end(potential_words), back_inserter(valid_words), valid_word);
        
        // copy value-frequency pairs into the map
        for_each(begin(valid_words), end(valid_words), [&word_map] (const string& word) { word_map[word]++; } ); 

        auto max_word = max_element(word_map.begin(), word_map.end(),
            [] (const pair<string,int>& v1, const pair<string,int>& v2) { return v1.first.size() < v2.first.size(); } );

        auto max_value = max_element(word_map.begin(), word_map.end(),
            [] (const pair<string,int>& v1, const pair<string,int>& v2) { return v1.second < v2.second; } );

        // store length of longest word and largest frequency for printing
        size_t length_w{max_word->first.size()};
        size_t length_f{to_string(max_value->second).length()};
        
        // Print command "-a"
        if (argv[2][0] == '-' && argv[2][1] == 'a')
        {
            cout << "Printing map in alphabetic order:" << endl;
            for_each(begin(word_map), end(word_map), [&length_w, &length_f] (const pair<string,int>& w) 
                { cout << left << setw(length_w) << w.first << " " << right << setw(length_f) << w.second << endl; } 
            );
        } 

        // Print command "-f"
        else if (argv[2][0] == '-' && argv[2][1] == 'f') 
        {
            // create vector of pairs to order the "map" by frequency value
            vector< pair<string,int> > tmp{};
            for_each(begin(word_map), end(word_map), [&tmp] (const pair<string,int>& w) 
                { tmp.push_back(make_pair(w.first, w.second)); } );
                
            sort(begin(tmp), end(tmp), [] (const pair<string,int>& p1, const pair<string,int>& p2) {return p1.second > p2.second; });

            cout << "Printing map in descending frequency:" << endl;
            for_each(begin(tmp), end(tmp), [&length_w, &length_f, &word_map] (const pair<string,int>& w) 
                { cout << right << setw(length_w) << w.first << " " << setw(length_f) << w.second << endl; } 
            );

        } 
        // Print command "-o"
        else if (argv[2][0] == '-' && argv[2][1] == 'o') 
        {
            // print in original order without frequency; specify length N
            if (argc < 4)
            {
                cerr << "Error: Third argument N missing.\nUsage: a.out FILE [-a] [-f] [-o N]" << endl;
                return 0;
            }

            int n{stoi(argv[3])};
            int count{0};

            // valid_words vector contains all words in original order
            for_each(begin(valid_words), end(valid_words), [&n, &count] (const string& w) 
                {   
                    count += w.size();  // increase line-character counter by length of word
                    if (count >= n) {  
                        cout << "\n" << w << " ";
                        count = w.size() + 1; // +1 for white space
                    } else {
                        cout << w << " ";
                        count++; // +1 for white space
                    }
                }
            );
            cout << endl;
        } 

        else 
        {
            cerr << "Error: Second argument missing or invalid.\nUsage: a.out FILE [-a] [-f] [-o N]" << endl;
            return 0;
        }

    }
}


bool remove_junk(string& word) 
{   
    // remove any junk that comes before the first character 
    if ( word.find_first_not_of("(\"'") > 0 )
        word.erase(0, word.find_first_not_of("(\"'"));

    // remove any junk that comes after the first character 
    if ( word.find_last_not_of("!?;,:.\"')") < (word.size()-1) )
        word.erase(word.find_last_not_of("!?;,:.\"\')") + 1);

    // remove trailing "'s" if present
    if ( word.size() > 2 && word.find_last_of('\'') == (word.size()-2) )
        word.erase(word.find_last_of('\''));

    return true;
}


bool valid_word(string& word)
{
    auto found_non_letter { find_if(begin(word), end(word), 
        [](char c) { return !(isalpha(c) || (c == '-')); }) };
    
    // this means that we have found some non-letters in the word (invalid word)
    if (found_non_letter != end(word))
        return false;
    
    // checking length of word --> invalid word if less than 3 letters
    if (word.size() < 3)
        return false;
        
    // check if there are any hyphens at beginning or end of word (invalid word, can only be within word)
    if ( (word.find_last_of("-") == (word.size()-1)) || (word.find_first_of("-") == 0 ) )
        return false;

    // check for any consecutive hyphens within the word (invalid word)
    if (word.find("--") < word.size())
        return false;

    // the word has passed all checks and is valid! convert it to lower-case
    std::transform(begin(word), end(word), begin(word), [] (unsigned char c) { return tolower(c); });

    return true;
}