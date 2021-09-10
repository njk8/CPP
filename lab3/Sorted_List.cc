#include "Sorted_List.h"

using namespace std;

Sorted_List::Sorted_List()
    : first(nullptr)
{}

Sorted_List::~Sorted_List()
{
    // if is_empty, then first == nullptr, which means that all values have been deleted
    while (!is_empty())
        remove_first();
}

// copy constructor
Sorted_List::Sorted_List(Sorted_List const& other)
{
    // if the other list is empty, set first to new empty link
    if ( other.first == nullptr ) 
    {
        first = other.first;
    } 
    else 
    {
        Link* tmp = new Link{other.first->value};
        first = tmp;
        Link* other_link{other.first->next};
        while (other_link != nullptr)
        {
            tmp->next = new Link{other_link->value};
            tmp = tmp->next;
            other_link = other_link->next;
        }
    }
}

// move constructor
Sorted_List::Sorted_List(Sorted_List&& other)
{
    first = other.first;
    other.first = nullptr;
}

// copy assignment
Sorted_List& Sorted_List::operator=(Sorted_List const& other)
{
    while (first != nullptr)
        remove_first();

    // call copy constructor here, to reuse code
    *this = Sorted_List{other};
    return *this;
}

// move assignment
Sorted_List& Sorted_List::operator=(Sorted_List&& other)
{
    while (first != nullptr)
        remove_first();
    
    first = other.first;
    other.first = nullptr;
    return *this;
}

void Sorted_List::insert(int val)
{   
    // this function is just for the user, because he cannot access links.

    /* insertion is achieved by calling the recursive insert function, only   
     * if the element has to go to the very left, we can insert it here */
    if ( is_empty() || (val < first->value) )
    {
        first = new Link{val, first};
    } else {
        recursive_insert(first, val);
    }
}

void Sorted_List::recursive_insert(Link* l, int val)
{
    if ( (l->next == nullptr) || (val < l->next->value) )
    {
        l->next = new Link{val, l->next};
    }
    else 
    {
        recursive_insert(l->next, val);
    }
}

void Sorted_List::remove(int val)
{
    if (is_empty())
        //cerr << "Cannot delete from empty list." << endl;
        return;
    else if (!contains(val))
        //cerr << "Cannot delete value " << val << ". The list does not contain it." << endl;
        return;
    else    
    {
        Link* curr{first};
        if (curr->value == val)
            Sorted_List::remove_first();
        else 
        {
            while (curr->next != nullptr)
            {
                if (curr->next->value == val)
                {
                    Link* previous{curr};
                    curr = curr->next;
                    previous->next = curr->next;
                    delete curr;
                    return;
                } else {
                    curr = curr->next;
                }
            }
        } 
    }    
}

void Sorted_List::remove_first()
{
    if (is_empty())
    {
        //cerr << "List is already empty, nothing to remove." << endl;
        return;
    } else {
        Link* curr{first};
        Link* next{first->next};
        curr->next = nullptr;
        delete curr;
        first = next;
    }
}

string Sorted_List::print_list() const
{
    Link* curr{first};
    ostringstream out;
    out << "{ ";
    while (curr != nullptr)
    {
        out << curr->value << " ";
        curr = curr->next;
    }
    out << "}";
    //cout << out.str() << endl;
    return out.str();
}

bool Sorted_List::is_empty() const
{
    return first == nullptr;  
}

int Sorted_List::size() const
{
    Link* curr{first};
    int count{};
    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

bool Sorted_List::contains(int val) const
{
    Link* curr{first};
    while (curr != nullptr)
    {
        if(curr->value == val)
            return true; 
        curr = curr->next;
    }
    return false;
}

int Sorted_List::get(int index) const
{
    int return_value{0};
    Link* curr{first};
    if (index > size())
    {
        //cerr << "Out of range error - Index is larger than size of list." << endl;
        return return_value;
    } else {
        for(int i=0; i<index; i++) {
            return_value = curr->value;
            curr = curr->next;            
        }
    }
    return return_value;        
}