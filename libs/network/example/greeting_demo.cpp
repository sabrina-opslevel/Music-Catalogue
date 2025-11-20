//            Copyright (c) 2024.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

/**
 * This is a simple demonstration of the greeting functionality in cpp-netlib.
 * It demonstrates how to use the sayHi() function both programmatically
 * and via command-line flags.
 */

#include <boost/network/greeting.hpp>
#include <iostream>
#include <string>

void print_usage(const char* program_name) {
  std::cout << "Usage: " << program_name << " [OPTIONS]" << std::endl;
  std::cout << "\nOptions:" << std::endl;
  std::cout << "  --say-hi        Output greeting message" << std::endl;
  std::cout << "  --help, -h      Display this help message" << std::endl;
  std::cout << "\nExample:" << std::endl;
  std::cout << "  " << program_name << " --say-hi" << std::endl;
}

int main(int argc, char *argv[]) {
  // If no arguments provided, show usage
  if (argc == 1) {
    print_usage(argv[0]);
    return 0;
  }

  // Parse command-line arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    
    if (arg == "--say-hi") {
      // Invoke the greeting function
      std::cout << "Invoking greeting function..." << std::endl;
      boost::network::sayHi();
      
      // Also demonstrate the getGreeting function
      std::string greeting = boost::network::getGreeting();
      std::cout << "Greeting string: " << greeting << std::endl;
      
      return 0;
    }
    else if (arg == "--help" || arg == "-h") {
      print_usage(argv[0]);
      return 0;
    }
    else {
      std::cerr << "Unknown option: " << arg << std::endl;
      print_usage(argv[0]);
      return 1;
    }
  }

  return 0;
}
