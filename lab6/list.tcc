#include <algorithm>
#include <iostream>

template <typename T>
void List<T>::insert(T const& t)
{
  first = new Link(t, first);
}

//-----------------------------------------------------//
// Important copy and assignment stuff
template <typename T>
typename List<T>::Link*
List<T>::Link::clone(Link const* dolly)
{
  if ( dolly != nullptr )
    return new Link(dolly->data, clone(dolly->next));
  else
    return nullptr;
}

template <typename T>
List<T>::List() : first(nullptr)
{
  std::clog << "***Default construction" << std::endl;
}

template <typename T>
List<T>::List(List<T> const& l)
{
  std::clog << "***Copy construction" << std::endl;
  first = Link::clone(l.first);
}

template <typename T>
List<T>::List(List<T>&& l)
{
  std::clog << "***Move construction" << std::endl;
  first = l.first;
  l.first = nullptr;
}

template <typename T>
List<T>& List<T>::operator=(List<T> const& rhs)
{
  std::clog << "***Copy assignment" << std::endl;
  if (&rhs != this)
  {
    List<T> copy(rhs);
    std::swap(first, copy.first);
  }
  return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& rhs)
{
  std::clog << "***Move assignment" << std::endl;
  if (&rhs != this)
  {
    std::swap(first, rhs.first);
  }
  return *this;
}

// own added functions (for iterator and ostream)

// Comparison operator != (to compare to end() iterator)
template<typename T> 
bool List<T>::iterator::operator!=(const List<T>::iterator &it) const
{
  return !(it.current == current);
}

// Preincrement operator ++ (to increment iterator)
template<typename T> 
typename List<T>::iterator &List<T>::iterator::operator++()
{
  current = current->next;
  return *this;
}

// Dereference (content) operator *
template<typename T> 
T List<T>::iterator::operator*() const
{
  return current->data;
}

// begin and end iterator to iterate through list
// begin() points to the first Link in the list
template<typename T> 
typename List<T>::iterator List<T>::begin() const
{ 
    return iterator{first}; 
} 
  
// end() points past-the-last element, which is nullpointer
template<typename T> 
typename List<T>::iterator List<T>::end() const
{ 
    return iterator{nullptr}; 
} 

// Stream output operator << (not a member function of List)
template <typename U>
std::ostream& operator<<(std::ostream& out, const List<U>& list)
{
  for (auto it = list.begin(); it != list.end(); ++it)
    out << *it << " ";
  return out;
}