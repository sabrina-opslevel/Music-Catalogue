// Copyright 2024 cpp-netlib contributors
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file hello_endpoint_server.cpp
 * @brief HTTP server with a /hello endpoint
 *
 * This example demonstrates an HTTP server with a dedicated /hello endpoint
 * that returns the standardized hello message. This satisfies the requirement
 * for "Add hello endpoint to API services where relevant".
 *
 * Usage:
 *   ./hello_endpoint_server 0.0.0.0 8000
 *   curl http://localhost:8000/hello
 */

#include <boost/network/protocol/http/server.hpp>
#include <boost/network/hello.hpp>
#include <iostream>
#include <string>

namespace http = boost::network::http;

struct hello_endpoint_handler;
typedef http::server<hello_endpoint_handler> server;

struct hello_endpoint_handler {
  void operator()(server::request const &request, server::connection_ptr connection) {
    std::string path = request.destination;

    // Handle /hello endpoint
    if (path == "/hello" || path == "/hello/") {
      std::string hello_msg = boost::network::get_hello_message_with_version();
      connection->set_status(server::connection::ok);
      connection->set_headers(std::map<std::string, std::string>{
        {"Content-Type", "text/plain"},
        {"Content-Length", std::to_string(hello_msg.length())}
      });
      connection->write(hello_msg);
      return;
    }

    // Handle /health endpoint (with hello message)
    if (path == "/health" || path == "/health/") {
      std::string health_msg = "OK - " + boost::network::get_hello_message();
      connection->set_status(server::connection::ok);
      connection->set_headers(std::map<std::string, std::string>{
        {"Content-Type", "text/plain"},
        {"Content-Length", std::to_string(health_msg.length())}
      });
      connection->write(health_msg);
      return;
    }

    // Default response
    std::string response = "cpp-netlib Server\n\nAvailable endpoints:\n  /hello - Get hello message\n  /health - Health check\n";
    connection->set_status(server::connection::ok);
    connection->set_headers(std::map<std::string, std::string>{
      {"Content-Type", "text/plain"},
      {"Content-Length", std::to_string(response.length())}
    });
    connection->write(response);
  }

  void log(server::string_type const &info) {
    std::cerr << "[INFO] " << info << std::endl;
  }
};

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " address port" << std::endl;
    std::cerr << "Example: " << argv[0] << " 0.0.0.0 8000" << std::endl;
    return 1;
  }

  try {
    // Print startup message with hello
    std::cout << boost::network::get_hello_message_with_version() << std::endl;
    std::cout << "Starting HTTP server on " << argv[1] << ":" << argv[2] << std::endl;
    std::cout << "Endpoints:" << std::endl;
    std::cout << "  - http://" << argv[1] << ":" << argv[2] << "/hello" << std::endl;
    std::cout << "  - http://" << argv[1] << ":" << argv[2] << "/health" << std::endl;

    hello_endpoint_handler handler;
    server::options options(handler);
    server server_(options.address(argv[1]).port(argv[2]));
    server_.run();
  }
  catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
