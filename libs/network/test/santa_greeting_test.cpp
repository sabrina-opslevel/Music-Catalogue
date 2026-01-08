// Copyright (c) cpp-netlib contributors
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_TEST_MODULE Santa Greeting Test

#include <boost/network/santa_greeting.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <sstream>
#include <iostream>

BOOST_AUTO_TEST_SUITE(santa_greeting_tests)

BOOST_AUTO_TEST_CASE(santa_greeting_returns_correct_message) {
  std::string greeting = boost::network::santa_greeting();
  BOOST_CHECK_EQUAL(greeting, "Hi Santa");
}

BOOST_AUTO_TEST_CASE(santa_greeting_not_empty) {
  std::string greeting = boost::network::santa_greeting();
  BOOST_CHECK(!greeting.empty());
}

BOOST_AUTO_TEST_CASE(santa_greeting_with_prefix_works) {
  std::string greeting = boost::network::santa_greeting_with_prefix("LOG");
  BOOST_CHECK_EQUAL(greeting, "LOG: Hi Santa");
}

BOOST_AUTO_TEST_CASE(santa_greeting_with_empty_prefix) {
  std::string greeting = boost::network::santa_greeting_with_prefix("");
  BOOST_CHECK_EQUAL(greeting, ": Hi Santa");
}

BOOST_AUTO_TEST_CASE(santa_greeting_consistency) {
  // Verify that multiple calls return the same greeting
  std::string greeting1 = boost::network::santa_greeting();
  std::string greeting2 = boost::network::santa_greeting();
  BOOST_CHECK_EQUAL(greeting1, greeting2);
}

BOOST_AUTO_TEST_CASE(print_santa_greeting_produces_output) {
  // Redirect cout to capture output
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
  
  boost::network::print_santa_greeting();
  
  // Restore cout
  std::cout.rdbuf(old);
  
  std::string output = buffer.str();
  BOOST_CHECK(output.find("Hi Santa") != std::string::npos);
}

BOOST_AUTO_TEST_SUITE_END()
