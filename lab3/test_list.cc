// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sorted_List.h"

#include <random>

using namespace std;

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};

  REQUIRE( l.is_empty() );
  REQUIRE( l.size() == 0 );
}

TEST_CASE( "Traverse / Print List" ) {
  Sorted_List l{};
  CHECK( l.print_list() == "{ }" );

  l.insert(1);
  CHECK( l.print_list() == "{ 1 }" );
}

TEST_CASE( "Insertion in right order" ) {
  Sorted_List l{};
  CHECK( l.is_empty() );
  CHECK( l.size() == 0 );

  l.insert(5);
  CHECK( l.print_list() == "{ 5 }" );
  CHECK( l.size() == 1 );
  CHECK_FALSE( l.is_empty() );

  l.insert(2);
  CHECK( l.print_list() == "{ 2 5 }" );
  CHECK( l.size() == 2 );

  l.insert(4);
  CHECK( l.print_list() == "{ 2 4 5 }" );
  CHECK( l.size() == 3 );

  l.insert(-6);
  CHECK( l.print_list() == "{ -6 2 4 5 }" );
  CHECK( l.size() == 4 );

  l.insert(10);
  CHECK( l.print_list() == "{ -6 2 4 5 10 }" );
  CHECK( l.size() == 5 );

  l.insert(0);
  CHECK( l.print_list() == "{ -6 0 2 4 5 10 }" );
  CHECK( l.size() == 6 );
}

TEST_CASE( "Get value at position" ) {
  Sorted_List l{};
  l.insert(1);
  l.insert(10);
  CHECK(l.get(1) == 1);
  CHECK(l.get(2) == 10);
  CHECK(l.get(3) == 0); // get() for invalid index will return default int value (0)
}

TEST_CASE ( "Remove value" ) {
  Sorted_List l{};
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  CHECK(l.print_list() == "{ 1 2 3 4 }");
  CHECK(l.size() == 4);

  // remove value that is not in list
  l.remove(5);
  CHECK(l.print_list() == "{ 1 2 3 4 }");
  CHECK(l.size() == 4);

  // removing first 4 (last value), then 2 (middle value), then 1 (first value), then 3
  l.remove(4);
  CHECK(l.print_list() == "{ 1 2 3 }");
  CHECK(l.size() == 3);

  l.remove(2);
  CHECK(l.print_list() == "{ 1 3 }");
  CHECK(l.size() == 2);

  l.remove(1);
  CHECK(l.print_list() == "{ 3 }");
  CHECK(l.size() == 1);

  l.remove(3);
  CHECK(l.print_list() == "{ }");
  CHECK(l.size() == 0);
  CHECK(l.is_empty());

  // try to remove value from empty list, just so see that nothing crashes
  l.remove(0);
  CHECK(l.size() == 0);
  CHECK(l.is_empty());
}

TEST_CASE ( "Delete first / destructor " ) {
  Sorted_List l{};
  // Inserting 3 links and then deleting them, one by one, mimicing the destructor syntax
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  l.insert(5);
  CHECK(l.print_list() == "{ 1 2 3 4 5 }");
  CHECK(l.size() == 5);

  l.remove_first();
  CHECK(l.print_list() == "{ 2 3 4 5 }");
  CHECK(l.size() == 4);

  // this is our destructor syntax as well, just to test it
  while (!l.is_empty())
    l.remove_first();

  CHECK(l.is_empty());
  CHECK(l.size() == 0);
}

TEST_CASE("Copy constructor") {
  Sorted_List l1{};
  l1.insert(3);
  l1.insert(5);
  l1.insert(55);
  l1.insert(1);
  l1.insert(9);
  l1.insert(6);

  // copying list l1 in new list l2 (deep copy)
  Sorted_List l2{l1};
  CHECK(l1.print_list() == l2.print_list());
  CHECK(l1.size() == l2.size());

  // make changes to l2 and check that l1 is not affected
  l2.remove_first();
  CHECK_FALSE(l1.print_list() == l2.print_list());
  CHECK(l1.size() > l2.size());
  CHECK(l1.print_list() == "{ 1 3 5 6 9 55 }");
}

TEST_CASE("Copy assginment") {
  Sorted_List l1{};
  l1.insert(3);
  l1.insert(5);
  l1.insert(55);
  l1.insert(1);
  l1.insert(9);
  l1.insert(6);

  Sorted_List l2{};

  // deep copy l1 to empty l2
  l2 = l1;
  CHECK(l1.print_list() == l2.print_list());
  CHECK(l1.size() == l2.size());

  // check that changing l2 does not affect l1 (deep copy)
  l2.remove_first();
  l2.remove_first();
  l2.insert(-4);
  CHECK_FALSE(l1.print_list() == l2.print_list());
  CHECK_FALSE(l1.size() == l2.size());
  // assigning copy to non-empty list should delete all previous values
  l2 = l1;
  CHECK(l1.print_list() == l2.print_list());
  CHECK(l1.size() == l2.size());

  // make sure that l1 is not affected by changes in l2 (deep copy)
  l2.insert(100);
  CHECK_FALSE(l1.print_list() == l2.print_list());
  CHECK(l1.size() < l2.size());
  CHECK(l1.print_list() == "{ 1 3 5 6 9 55 }");
}

TEST_CASE("Move constructor") {
  Sorted_List l1{};
  l1.insert(3);
  l1.insert(5);
  l1.insert(55);
  CHECK(l1.print_list() == "{ 3 5 55 }");
  CHECK(l1.size() == 3);

  // constructing new list l2 and moving values from l1 to l2
  Sorted_List l2{move(l1)};
  CHECK(l2.print_list() == "{ 3 5 55 }");
  CHECK(l2.size() == 3);
  CHECK(l1.is_empty());
  CHECK(l1.size() == 0);
}

TEST_CASE("Move assignment") {
  Sorted_List l1{};
  l1.insert(3);
  l1.insert(5);
  l1.insert(55);
  CHECK(l1.print_list() == "{ 3 5 55 }");
  CHECK(l1.size() == 3);

  // moving values of l1 to empty l2
  Sorted_List l2{};
  l2 = move(l1);
  CHECK(l2.print_list() == "{ 3 5 55 }");
  CHECK(l2.size() == 3);
  CHECK(l1.is_empty());
  CHECK(l1.size() == 0);

  // moving values of l2 to filled l1 (should delete old values from l1)
  l1.insert(-1);
  CHECK(l1.size() == 1);
  l1 = move(l2);
  CHECK(l1.print_list() == "{ 3 5 55 }");
  CHECK(l1.size() == 3);
  CHECK(l2.is_empty());
  CHECK(l2.size() == 0);
}
