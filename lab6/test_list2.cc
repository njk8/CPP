#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> list;
    // The list is filled with data here...
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    // ...
    for ( auto it = list.begin(); it != list.end(); ++it)
    {
    cout << *it << endl;
    }

    List<std::string> word_list;
    // The list is filled with data here...
    word_list.insert("hello");
    word_list.insert("this");
    word_list.insert("is");
    word_list.insert("a");
    word_list.insert("test");
    // ...
    // Once the above work, try this
    for ( auto s : word_list )
    {
    cout << s << endl;
    }
    // Printing entire list (as above but shorter...)
    cout << list << endl;
    cout << word_list << endl;
}