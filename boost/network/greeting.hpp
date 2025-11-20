//          Copyright Dean Michael Berris 2007.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_NETWORK_GREETING_HPP__
#define BOOST_NETWORK_GREETING_HPP__

#include <iostream>
#include <string>

namespace boost {
namespace network {

/**
 * @brief Outputs a greeting message "Hi" to standard output
 * 
 * This function provides a standardized greeting capability that can be
 * invoked programmatically across the organization's codebases.
 * 
 * @return void
 * 
 * Example usage:
 * @code
 * boost::network::sayHi();
 * @endcode
 */
inline void sayHi() {
  std::cout << "Hi" << std::endl;
}

/**
 * @brief Returns a greeting message as a string
 * 
 * This function returns the greeting message "Hi" as a string without
 * outputting to standard output.
 * 
 * @return std::string containing "Hi"
 * 
 * Example usage:
 * @code
 * std::string greeting = boost::network::getGreeting();
 * @endcode
 */
inline std::string getGreeting() {
  return "Hi";
}

}  // namespace network
}  // namespace boost

#endif  // BOOST_NETWORK_GREETING_HPP__
