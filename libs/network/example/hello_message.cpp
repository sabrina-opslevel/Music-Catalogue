// Copyright 2024 cpp-netlib contributors
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file hello_message.cpp
 * @brief Example program demonstrating the hello message functionality
 *
 * This example shows how to use the standardized hello message functionality
 * in cpp-netlib. The hello message can be customized via the
 * CPPNETLIB_HELLO_MESSAGE environment variable.
 *
 * Usage:
 *   ./hello_message
 *   CPPNETLIB_HELLO_MESSAGE="Custom Hello!" ./hello_message
 */

#include <boost/network/hello.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "=== cpp-netlib Hello Message Example ===" << std::endl;
  std::cout << std::endl;

  // Get the basic hello message
  std::cout << "Basic message: " << boost::network::get_hello_message() << std::endl;

  // Get the hello message with version
  std::cout << "With version:  " << boost::network::get_hello_message_with_version() << std::endl;

  std::cout << std::endl;
  std::cout << "Tip: Set CPPNETLIB_HELLO_MESSAGE environment variable to customize the message!" << std::endl;

  return 0;
}
