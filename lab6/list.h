#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <string>

/*
TODO:
Your iterator constructor should be private. An iterator should only be able to
be created using begin or end. 

Since your iterators returned by begin and end are const your dereference
operator should also be const aswell as returning either const& or a copy.
This is because you shouldn't be able to change the values in a const iterator.

operator != should also be const
*/

template <typename T>
class List
{
public:
  List();
  ~List() { delete first; }

  void insert(T const& t);
  
  List(List<T> const&);
  List(List<T>&&);
  List& operator=(List<T> const&);
  List& operator=(List<T>&&);

private:

  class Link
  {
  public:
    Link(T const& t, Link* n)
      : data(t), next(n) {}
    ~Link() { delete next; }
    
    friend class List;

    static Link* clone(Link const*);
    
  private:
    
    T data;
    Link* next;
  };
  
  Link* first;
  
public:

  using value_type = T;

  // Suitable place to add things...

  class iterator
  {
  public:
    // make list a friend class (so that e.g. private constructor can be accessed)
    friend class List;

    // Operator overloading:
    // Comparison operator != (to compare to end() iterator)
    bool operator!=(iterator const& it) const;

    // Preincrement operator ++ (to increment iterator)
    iterator& operator++();

    // Dereference (content) operator *
    T operator*() const;

  private:
    // keep track of the current position in the list
    Link* current;

    // constructor, so that we can create an iterator, e.g. iterator{first}
    iterator(Link* l)
      : current(l) {}
  };

  // begin and end iterator to iterate through list
  iterator begin() const;
  iterator end() const;
};

// Stream output operator << (as non-member function, otherwise it can only take one argument)
template <typename U>
std::ostream& operator<<(std::ostream& out, const List<U>& list);

#include "list.tcc"
#endif