#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <iostream>
#include <sstream>
//These comments are for all your code

//TODO: Complementary work neeed, 4-6: Do not repeat similar code -- DONE
//TOD: Complementary work needed, 8-8: When using catch for testing you
// should not print to the terminal -- DONE

//COMMENT: Good testcases!
//COMMENT: Good job with no memory leaks! 

class Sorted_List
{
public:
    Sorted_List();
    ~Sorted_List();

    Sorted_List(Sorted_List const& other);              // copy constructor
    Sorted_List(Sorted_List&& other);                   // move constructor
    Sorted_List& operator=(Sorted_List const& other);   // copy assignment
    Sorted_List& operator=(Sorted_List&& other);        // move assignment

    void insert(int val);
    void remove(int val);
    void remove_first();
    std::string print_list() const;
    bool is_empty() const;
    int size() const;
    bool contains(int val) const;
    int get(int index) const;

private:
    struct Link
    {
        int value{};
        Link* next{};
    };
    void recursive_insert(Link* l, int val);
    Link* first{};
};

#endif
