#include "Time.h"

using namespace std;

string to_string(Time t, bool am)
{
    stringstream output;
    output << setfill('0');

    if (!am)
    {
        output << setw(2) << t.hh << ":" << setw(2) << t.mm << ":" 
               << setw(2) << t.ss;
        return output.str();
    }

    else if (am)
    {
        string p{"am"};
        if (!is_am(t))
        {
            t.hh -= 12;
            p = "pm";
        }
        output.clear();
        output << setfill('0');
        output << setw(2) << t.hh << ":" << setw(2) << t.mm << ":" 
               << setw(2) << t.ss << " " << p;
        return output.str();
    }

    return "";
}

bool is_valid(Time const & t)
{
    if (t.hh < 0 || t.hh > 23)
    {
        return false;
    }

    if (t.mm < 0 || t.mm > 59)
    {
        return false;
    }

    if (t.ss < 0 || t.ss > 59)
    {
        return false;
    }

    return true;
}


bool is_am(Time const & t)
{
    if (t.hh > 12)
    {
        return false;
    } else {
        return true;
    }
}


Time operator+(Time const & t, int seconds)
{
    Time new_t = t;
    
    new_t.ss += seconds;

    while (new_t.ss > 59)
    {
        new_t.ss -= 60;
        new_t.mm += 1;
    }

    while (new_t.mm > 59)
    {
        new_t.mm -= 60;
        new_t.hh += 1;
    }

    new_t.hh = new_t.hh % 24;

    //cout << to_string(new_t, 24) << endl;

    return new_t;
}


Time operator-(Time const & t, int seconds)
{
    Time new_t = t;
    
    new_t.ss -= seconds;

    while (new_t.ss < 0)
    {
        new_t.ss += 60;
        new_t.mm -= 1;
    }

    while (new_t.mm < 0)
    {
        new_t.mm += 60;
        new_t.hh -= 1;
    }

    while(new_t.hh < 0)
    {
        new_t.hh += 24;
    }
    //cout << to_string(new_t, 24) << endl;

    return new_t;
}

Time operator++(Time & t, int)
{
    Time told{t};
    t = t + 1;
    return told;
}

Time operator--(Time & t, int)
{   
    Time told{t};
    t = t - 1;
    return told;

}

Time& operator++(Time& t)
{
    t = t + 1;
    return t;
}

Time& operator--(Time& t)
{
    t = t - 1;
    return t;
}

bool operator==(Time const & t1, Time const & t2)
{
    if ((t1.hh == t2.hh) && (t1.mm == t2.mm) && (t1.ss == t2.ss))
        return true;
    else
        return false;    
}

bool operator!=(Time const & t1, Time const & t2)
{
    return !(t1 == t2);
}

bool operator>=(Time const & t1, Time const & t2)
{
    if ((t1 > t2) || (t1 == t2))
        return true;
    else
        return false;        
}

bool operator<=(Time const & t1, Time const & t2)
{
    if ((t1 < t2) || (t1 == t2))
        return true;
    else
        return false;  
}

bool operator>(Time const & t1, Time const & t2)
{
    if (t1.hh > t2.hh)
        return true;
    else if (t1.hh == t2.hh)
    {
        if (t1.mm > t2.mm)
            return true;
        else if (t1.mm == t2.mm)
        {
            if (t1.ss > t2.ss)
                return true;    
        } 
    }
    return false;
}

bool operator<(Time const & t1, Time const & t2)
{
    return !(t1 >= t2);
}

ostream& operator<<(ostream& os, Time const& t)
{
    os << setfill('0') << setw(2) << t.hh << ":" << setw(2) << t.mm << ":" << setw(2) << t.ss;    
    return os;
}

istream& operator>>(istream& is, Time& t)
{
 char colon{};
 is >> t.hh >> colon >> t.mm >> colon >> t.ss;
 if (!is_valid(t))
 {
 cin.setstate(ios_base::failbit);
 t = {};
 } 
 return is;
}

/*
istream& operator>>(istream& is, Time & t)
{
    if((t.ss >= 0 && t.ss<=59) || (t.mm >= 0 && t.mm<=59) || (t.hh >= 0 && t.hh<=23))
    {
        //fflag=0;
    }
    else
    {
        //fflag=1;
    }
    return is;       
}
*/