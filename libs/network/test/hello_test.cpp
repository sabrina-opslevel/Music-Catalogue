// Copyright 2024 cpp-netlib contributors
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file hello_test.cpp
 * @brief Unit tests for the hello message functionality
 *
 * This test suite verifies the hello message functionality works correctly,
 * including environment variable customization.
 */

#include <boost/network/hello.hpp>
#include <gtest/gtest.h>
#include <cstdlib>

using namespace boost::network;

class HelloTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Save original environment variable if it exists
    const char* orig = std::getenv("CPPNETLIB_HELLO_MESSAGE");
    if (orig != nullptr) {
      original_value_ = orig;
      has_original_ = true;
    }
  }

  void TearDown() override {
    // Restore original environment variable
    if (has_original_) {
      setenv("CPPNETLIB_HELLO_MESSAGE", original_value_.c_str(), 1);
    } else {
      unsetenv("CPPNETLIB_HELLO_MESSAGE");
    }
  }

  std::string original_value_;
  bool has_original_ = false;
};

TEST_F(HelloTest, DefaultMessageIsNotEmpty) {
  unsetenv("CPPNETLIB_HELLO_MESSAGE");
  std::string message = get_hello_message();
  EXPECT_FALSE(message.empty());
  EXPECT_EQ(message, "Hello from cpp-netlib!");
}

TEST_F(HelloTest, CustomMessageFromEnvironment) {
  setenv("CPPNETLIB_HELLO_MESSAGE", "Custom Hello!", 1);
  std::string message = get_hello_message();
  EXPECT_EQ(message, "Custom Hello!");
}

TEST_F(HelloTest, EmptyEnvironmentVariableUsesDefault) {
  setenv("CPPNETLIB_HELLO_MESSAGE", "", 1);
  std::string message = get_hello_message();
  EXPECT_EQ(message, "Hello from cpp-netlib!");
}

TEST_F(HelloTest, MessageWithVersionContainsVersion) {
  unsetenv("CPPNETLIB_HELLO_MESSAGE");
  std::string message = get_hello_message_with_version();
  EXPECT_FALSE(message.empty());
  EXPECT_TRUE(message.find("version") != std::string::npos);
  EXPECT_TRUE(message.find("0.12.0") != std::string::npos);
}

TEST_F(HelloTest, MessageWithVersionContainsBaseMessage) {
  unsetenv("CPPNETLIB_HELLO_MESSAGE");
  std::string base_message = get_hello_message();
  std::string version_message = get_hello_message_with_version();
  EXPECT_TRUE(version_message.find(base_message) == 0);
}

TEST_F(HelloTest, CustomMessageWithVersion) {
  setenv("CPPNETLIB_HELLO_MESSAGE", "Greetings", 1);
  std::string message = get_hello_message_with_version();
  EXPECT_TRUE(message.find("Greetings") == 0);
  EXPECT_TRUE(message.find("version") != std::string::npos);
}
