#ifndef BOOST_NETWORK_SANTA_GREETING_HPP
#define BOOST_NETWORK_SANTA_GREETING_HPP

// Copyright (c) cpp-netlib contributors
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include <iostream>

namespace boost {
namespace network {

/**
 * @brief Returns the Santa greeting message.
 * 
 * This function returns a standardized greeting message "Hi Santa" that can be
 * used across all organization repositories for consistent greetings.
 * 
 * @return std::string containing "Hi Santa"
 */
inline std::string santa_greeting() {
  return "Hi Santa";
}

/**
 * @brief Prints the Santa greeting to standard output.
 * 
 * This function prints the Santa greeting message to std::cout, followed by
 * a newline character. This is useful for CLI applications and logging.
 */
inline void print_santa_greeting() {
  std::cout << santa_greeting() << std::endl;
}

/**
 * @brief Returns the Santa greeting with a custom prefix.
 * 
 * This function returns a Santa greeting with a custom prefix message,
 * useful for creating contextualized greetings.
 * 
 * @param prefix The prefix to add before the greeting
 * @return std::string containing the formatted greeting
 */
inline std::string santa_greeting_with_prefix(const std::string& prefix) {
  return prefix + ": " + santa_greeting();
}

}  // namespace network
}  // namespace boost

#endif  // BOOST_NETWORK_SANTA_GREETING_HPP
