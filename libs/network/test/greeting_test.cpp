// Copyright 2024.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>
#include <boost/network/greeting.hpp>
#include <sstream>
#include <iostream>

namespace {

// Test that getGreeting returns the expected string
TEST(GreetingTest, GetGreeting) {
  std::string greeting = boost::network::getGreeting();
  ASSERT_EQ(greeting, "Hi");
}

// Test that sayHi outputs to stdout correctly
TEST(GreetingTest, SayHi) {
  // Redirect std::cout to a stringstream to capture output
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
  
  boost::network::sayHi();
  
  // Restore original std::cout
  std::cout.rdbuf(old);
  
  // Verify the output
  std::string output = buffer.str();
  ASSERT_EQ(output, "Hi\n");
}

// Test that greeting function can be called multiple times
TEST(GreetingTest, MultipleInvocations) {
  // Redirect std::cout to a stringstream to capture output
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
  
  boost::network::sayHi();
  boost::network::sayHi();
  
  // Restore original std::cout
  std::cout.rdbuf(old);
  
  // Verify the output
  std::string output = buffer.str();
  ASSERT_EQ(output, "Hi\nHi\n");
}

// Test that getGreeting always returns the same value
TEST(GreetingTest, Consistency) {
  std::string greeting1 = boost::network::getGreeting();
  std::string greeting2 = boost::network::getGreeting();
  ASSERT_EQ(greeting1, greeting2);
  ASSERT_EQ(greeting1, "Hi");
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
