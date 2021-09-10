#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Time.h"
#include <sstream>

using namespace std;

TEST_CASE("Time valid")
{
    Time time{10, 11, 12};
    CHECK(is_valid(time));
    time.hh=-5;
    CHECK_FALSE(is_valid(time));
}

TEST_CASE("To string")
{
    Time time{18, 11, 12};
    //cout << to_string(time, 24) << endl;
    //cout << to_string(time, 12) << endl;
    CHECK(to_string(time, false) == "18:11:12");
    CHECK(to_string(time, true) == "06:11:12 pm");
}

TEST_CASE("Is am")
{
    Time time{18, 11, 12};
    CHECK_FALSE(is_am(time));
    time.hh = 8;
    CHECK(is_am(time));
}

TEST_CASE("Add seconds")
{
    Time time{23, 59, 59};
    Time time1{};
    CHECK(to_string(time1+5,false) == "00:00:05");
    time = time + 200;
    CHECK((time.hh == 0 && time.mm == 3 && time.ss == 19));
    time1=time1+(24*60*60*10); // Trying to add Ten days.
     CHECK((time1.hh == 0 && time1.mm == 0 && time1.ss == 0));
}

TEST_CASE("Subtract seconds")
{
    // TODO LOOP
    Time time{};
    Time time1{};
    CHECK(to_string(time-5,false) == "23:59:55");
    time = time - 5;
    CHECK((time.hh == 23 && time.mm == 59 && time.ss == 55));
    time1=time1-(24*60*60*10); // Trying to substract Ten days.
     CHECK((time1.hh == 0 && time1.mm == 0 && time1.ss == 0));
}

TEST_CASE("Increment time")
{
    Time time{};
    Time temp{};
    //t++ == Time{0,0,0}
    CHECK((time++)==temp);
    CHECK((time.hh == 0 && time.mm == 0 && time.ss == 1));
    temp.ss=2;
    CHECK((++time)==temp);
    CHECK((time.hh == 0 && time.mm == 0 && time.ss == 2));
}

TEST_CASE("Decrement time")
{
    Time time{};
    Time temp{};
    
    CHECK((time--)==temp);
    CHECK((time.hh == 23 && time.mm == 59 && time.ss == 59)); 
    temp=temp-2;
    CHECK((--time)==temp);
    CHECK((time.hh == 23 && time.mm == 59 && time.ss == 58)); 
}

TEST_CASE("Comparison")
{
    Time t1{00, 00, 01};
    Time t2{12, 30, 40};
    CHECK_FALSE(t1 > t2);
    CHECK(t2>t1);
    CHECK(t1 < t2);
    CHECK_FALSE(t2 < t1);
    CHECK_FALSE(t1 >= t2);
    CHECK(t2 >= t1);
    CHECK(t1 <= t2);
    CHECK_FALSE(t2 <= t1);
    CHECK_FALSE(t1 == t2);
    CHECK(t1 != t2);

    t1 = t2;
    CHECK_FALSE(t1 > t2);
    CHECK_FALSE(t1 < t2);
    CHECK(t1 >= t2);
    CHECK(t1 <= t2);
    CHECK(t1 == t2);
    CHECK_FALSE(t1 != t2);    
}

TEST_CASE("Out stream")
{
    Time time{23, 59, 1};
    ostringstream oss{};
    oss << time;
    CHECK(oss.str() == "23:59:01");
}

TEST_CASE("In stream")
{
 Time t_ref1{10, 5, 0};
 Time t_ref2{10, 5, -5};
 Time time{};
 
 istringstream iss{to_string(t_ref1, false) + " " + to_string(t_ref2, false)};
 
 // test to enter valid time
 iss >> time;
 CHECK(time == t_ref1);
 
 // test to enter invalid time
 iss >> time;
 CHECK(cin.fail());
 CHECK_FALSE(time == t_ref2);
}




/*
TEST_CASE("Input stream")
{
    Time time{};    
    istringstream iss{"23:59:01"};
    iss >> time;
    CHECK(iss.str() == "23:59:01");
    //cin.fail();
}
*/