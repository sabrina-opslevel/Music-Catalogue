// Copyright 2024 cpp-netlib contributors
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_NETWORK_HELLO_HPP_
#define BOOST_NETWORK_HELLO_HPP_

#include <string>
#include <cstdlib>

namespace boost {
namespace network {

/**
 * @brief Get standardized hello message for the cpp-netlib library
 *
 * This function returns a hello message that can be customized via
 * the CPPNETLIB_HELLO_MESSAGE environment variable. If not set,
 * it returns a default message.
 *
 * @return std::string The hello message
 */
inline std::string get_hello_message() {
  const char* custom_message = std::getenv("CPPNETLIB_HELLO_MESSAGE");
  if (custom_message != nullptr && custom_message[0] != '\0') {
    return std::string(custom_message);
  }
  return "Hello from cpp-netlib!";
}

/**
 * @brief Get hello message with version information
 *
 * @return std::string The hello message with version info
 */
inline std::string get_hello_message_with_version() {
  return get_hello_message() + " (version 0.12.0)";
}

}  // namespace network
}  // namespace boost

#endif  // BOOST_NETWORK_HELLO_HPP_
