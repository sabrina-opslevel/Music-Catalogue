# C++ Network Library (cpp-netlib)

[![Build Status](https://travis-ci.org/cpp-netlib/cpp-netlib.svg?branch=master)](https://travis-ci.org/cpp-netlib/cpp-netlib)
[![Coverity Scan](https://scan.coverity.com/projects/6714/badge.svg)](https://scan.coverity.com/projects/cpp-netlib)

Modern C++ network programming libraries providing robust cross-platform networking capabilities.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Building from Source](#building-from-source)
- [Running Tests](#running-tests)
- [Contributing](#contributing)
- [Community](#community)
- [License](#license)
- [Contact](#contact)

## Overview

cpp-netlib is a collection of network-related routines and implementations geared towards providing a robust cross-platform networking library. The library is designed to be modular, easy to use, and provides modern C++ interfaces for network programming.

## Features

cpp-netlib offers the following implementations:

- **Common Message Type** - A generic message type which can be used to encapsulate and store message-related information, used by all network implementations as the primary means of data exchange
- **Network Protocol Message Parsers** - A collection of parsers which generate message objects from strings
- **Adapters and Wrappers** - A collection of adapters and wrappers aimed towards making the message type STL-friendly
- **Network Protocol Client and Server Implementations** - A collection of network protocol implementations that include embeddable client and server types
- **HTTPS Support** - Optional HTTPS support with OpenSSL integration

## Prerequisites

To build and use cpp-netlib, you will need:

- **C++ Compiler**:
  - GCC 4.x or higher
  - Clang 3.6 or higher
  - MSVC 2008 or higher
- **CMake**: Version 2.8 or higher
- **Boost**: Version 1.57.0 or higher
- **OpenSSL**: Optional, for HTTPS support
- **Git**: For cloning the repository and managing submodules

You can verify your CMake version with:

```bash
cmake --version
```

## Installation

### Downloading cpp-netlib

Official release packages can be found at:
```
http://github.com/cpp-netlib/cpp-netlib/downloads
```

### Cloning the Repository

To get the latest code from the master branch:

```bash
git clone https://github.com/cpp-netlib/cpp-netlib
cd cpp-netlib
git submodule init
git submodule update
```

## Usage

### Basic HTTP Client Example

Here's a simple example demonstrating how to use the HTTP client:

```cpp
#include <boost/network/protocol/http/client.hpp>
#include <boost/network/uri.hpp>
#include <iostream>

namespace http = boost::network::http;

int main() {
    http::client client;
    http::client::request request("http://www.example.com/");
    http::client::response response = client.get(request);

    std::cout << body(response) << std::endl;

    return 0;
}
```

### More Examples

Additional examples can be found in the `libs/network/example` directory, including:

- `simple_wget.cpp` - A basic wget clone
- `http_client1.cpp` - HTTP client demonstrations
- `trivial_google.cpp` - Simple Google query example

## Building from Source

It is recommended to build cpp-netlib outside of the source directory to avoid polluting the source tree with CMake-generated files.

### Build Steps

1. **Create a build directory:**

```bash
mkdir ~/cpp-netlib-build
cd ~/cpp-netlib-build
```

2. **Configure with CMake:**

```bash
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_C_COMPILER=clang \
      -DCMAKE_CXX_COMPILER=clang++ \
      ~/cpp-netlib
```

3. **Build the project:**

```bash
make
```

4. **Run tests:**

```bash
make test
```

### Build Options

The following CMake options are available:

- `CPP-NETLIB_BUILD_SHARED_LIBS` - Build as shared libraries (default: OFF)
- `CPP-NETLIB_BUILD_TESTS` - Build the project tests (default: ON)
- `CPP-NETLIB_BUILD_EXAMPLES` - Build the project examples (default: ON)
- `CPP-NETLIB_ENABLE_HTTPS` - Enable HTTPS support if OpenSSL is found (default: ON)

Example with custom options:

```bash
cmake -DCPP-NETLIB_BUILD_SHARED_LIBS=ON \
      -DCPP-NETLIB_ENABLE_HTTPS=ON \
      ~/cpp-netlib
```

## Running Tests

To run the test suite:

```bash
cd ~/cpp-netlib-build
make test
```

If any tests fail, you can find detailed logs in the `Testing/Temporary/` directory. Please report test failures to the [developers mailing list](mailto:cpp-netlib@googlegroups.com) with these logs attached.

## Contributing

cpp-netlib follows the GitHub pull request model for accepting contributions. Here's how to contribute:

1. **Fork the repository** on GitHub
2. **Clone your fork** locally
3. **Create a feature branch** for your changes
4. **Make your changes** following the [style guide](http://cpp-netlib.org/style-guide.html)
5. **Add your copyright notice** to any files you modify (alongside existing notices)
6. **Submit a pull request** to the main repository

### Important Notes

- The library is released under the Boost Software License
- Please add your copyright notice alongside original authors' notices in modified files
- Follow the cpp-netlib style guide available at http://cpp-netlib.org/style-guide.html
- For more details on the contribution process, visit http://cpp-netlib.org/process.html#pull-requests

### Code of Conduct

Please note that this project has a [Code of Conduct](code_of_conduct.md). By participating in this project, you agree to abide by its terms.

## Community

### Communication Channels

- **Slack**: Join us at http://slack.cpp-netlib.org/
- **Mailing List**: Subscribe to the [developers mailing list](https://groups.google.com/forum/#!forum/cpp-netlib)
- **Issues**: Report bugs and feature requests at http://github.com/cpp-netlib/cpp-netlib/issues

### Getting Help

If you have questions or would like to make feature requests, you can:

- Contact the development team through the [mailing list](mailto:cpp-netlib@googlegroups.com)
- File issues on [GitHub](http://github.com/cpp-netlib/cpp-netlib/issues)
- Join the conversation on [Slack](http://slack.cpp-netlib.org/)

## License

This library is released under the **Boost Software License, Version 1.0**.

See the [LICENSE_1_0.txt](LICENSE_1_0.txt) file for the full license text, or visit http://www.boost.org/LICENSE_1_0.txt

## Contact

### Maintainers

- **Dean Michael Berris** - [dberris@google.com](mailto:dberris@google.com)
- **Glyn Matthews** - [glyn.matthews@gmail.com](mailto:glyn.matthews@gmail.com)

### Links

- **Main Repository**: http://github.com/cpp-netlib/cpp-netlib
- **Documentation**: http://cpp-netlib.org/
- **Style Guide**: http://cpp-netlib.org/style-guide.html
- **Process Documentation**: http://cpp-netlib.org/process.html

---

*For additional information and detailed documentation, please visit the [official cpp-netlib website](http://cpp-netlib.org/).*
