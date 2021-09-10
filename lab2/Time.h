#ifndef TIME_H
#define TIME_H
#include <string>
#include <iostream>
#include <iomanip>

struct Time
{
    int hh{};
    int mm{};
    int ss{};
};

//int fflag;

std::string to_string(Time t, bool am);

bool is_valid(Time const & t);

bool is_am(Time const & t);

Time operator+(Time const & t, int seconds);

Time operator-(Time const & t, int seconds);

Time operator++(Time & t, int);

Time operator--(Time & t, int);

Time& operator++(Time& t);

Time& operator--(Time& t);

bool operator==(Time const & t1, Time const & t2);

bool operator!=(Time const & t1, Time const & t2);

bool operator>=(Time const & t1, Time const & t2);

bool operator<=(Time const & t1, Time const & t2);

bool operator>(Time const & t1, Time const & t2);

bool operator<(Time const & t1, Time const & t2);

std::ostream& operator<<(std::ostream& os, Time const& t);

std::istream& operator>>(std::istream& is, Time & t);
#endif