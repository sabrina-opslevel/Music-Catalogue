# Repository Structure

This document provides a comprehensive overview of the cpp-netlib repository structure.

## Overview

cpp-netlib is a modern C++ network programming library that provides:
- HTTP client and server implementations
- URI parsing and manipulation
- Message processing and transformation
- MIME type handling
- Asynchronous I/O support

## High-Level Architecture

```
cpp-netlib/
├── boost/           # Library headers (boost namespace)
│   └── network/     # Network library implementation
├── deps/            # Third-party dependencies
├── libs/            # Library source, tests, and examples
│   ├── mime/        # MIME handling library
│   └── network/     # Network library implementation
└── [build files]    # CMake and build scripts
```

## Directory Tree

### cpp-netlib (root)
 - Root directory of the cpp-netlib project - a modern C++ network programming l...
- **boost/** - Top-level boost namespace directory containing the main library headers for c...
  - **network/** - Core network library implementation including message types, protocol impleme...
    - **detail/** - Internal implementation details and base classes used throughout the network ...
    - **include/** - Additional include files for network functionality.
      - **http/** - HTTP-specific header files and includes.
    - **message/** - Generic message type that encapsulates message-related information used by al...
      - **directives/** - Directive implementations for manipulating message objects.
        - **detail/** - Internal implementation details for message directives.
      - **modifiers/** - Modifier implementations for changing message properties.
      - **traits/** - Type traits and compile-time properties for message types.
      - **transformers/** - Transformer implementations for converting message formats.
      - **wrappers/** - Wrapper implementations providing STL-friendly interfaces for message types.
    - **protocol/** - Network protocol implementations including HTTP client and server.
      - **http/** - Complete HTTP protocol implementation including client, server, message handl...
        - **algorithms/** - Algorithm implementations for HTTP operations.
        - **client/** - HTTP client implementation with support for various connection types.
          - **connection/** - HTTP client connection implementations for different connection types and pro...
        - **impl/** - Internal implementation details for HTTP protocol support.
        - **message/** - HTTP-specific message type implementations.
          - **directives/** - Directive implementations specific to HTTP messages.
          - **header/** - HTTP header parsing and manipulation implementations.
          - **modifiers/** - Modifier implementations specific to HTTP messages.
          - **traits/** - Type traits specific to HTTP message types.
          - **wrappers/** - Wrapper implementations specific to HTTP messages.
        - **parser/** - HTTP message parsing implementation.
        - **policies/** - Policy-based design implementations for HTTP functionality.
        - **server/** - HTTP server implementation with support for asynchronous operations.
          - **impl/** - Internal implementation details for the HTTP server.
        - **support/** - Support utilities and helper functions for HTTP operations.
        - **traits/** - Type traits for HTTP protocol support.
          - **impl/** - Internal implementation details for HTTP traits.
    - **support/** - General support utilities for the network library.
    - **traits/** - Type traits and compile-time properties for network types.
    - **uri/** - URI parsing, manipulation, and directive implementations.
      - **detail/** - Internal implementation details for URI handling.
      - **directives/** - Directive implementations for URI manipulation.
    - **utils/** - Utility functions and helper classes for network operations.
      - **base64/** - Base64 encoding and decoding implementations.
- **deps/** - External dependencies required by cpp-netlib.
  - **asio/** - Asio library for cross-platform asynchronous I/O operations.
  - **cxxopts/** - Lightweight C++ command-line option parser.
  - **googlemock/** - Google Mock framework for creating mock objects in tests.
  - **googletest/** - Google Test framework for unit testing.
- **libs/** - Library-specific implementations, tests, examples, and documentation.
  - **mime/** - MIME type handling and message processing library.
    - **doc/** - Documentation for the MIME library.
    - **example/** - Example code demonstrating MIME library usage.
    - **test/** - Unit tests for the MIME library.
      - **TestMessages/** - Sample MIME messages used in testing.
  - **network/** - Main network library implementation including source code, tests, examples, a...
    - **benchmarks/** - Performance benchmarks for measuring compile-time and run-time performance.
    - **build/** - Build configuration and CMake files for the network library.
    - **doc/** - Comprehensive documentation for the network library.
      - **_ext/** - Custom extensions for documentation generation.
        - **breathe/** - Breathe extension for integrating Doxygen with Sphinx documentation.
      - **_static/** - Static assets (CSS, JavaScript, images) for documentation.
      - **examples/** - Example code and usage patterns for documentation.
        - **http/** - Documentation for HTTP client and server examples.
      - **html/** - Generated HTML documentation output.
        - **_sources/** - Source files for generated HTML documentation.
          - **examples/** - Source files for example documentation pages.
            - **http/** - Source files for HTTP example documentation.
          - **reference/** - Source files for API reference documentation.
        - **_static/** - Static assets for HTML documentation pages.
        - **examples/** - Generated HTML pages for examples.
          - **http/** - Generated HTML pages for HTTP examples.
        - **reference/** - Generated HTML API reference pages.
      - **reference/** - Detailed API reference documentation source files.
    - **example/** - Example applications demonstrating network library usage.
      - **atom/** - Examples demonstrating Atom feed parsing and processing.
      - **http/** - HTTP client and server example applications.
        - **ssl/** - Examples demonstrating HTTPS with SSL/TLS support.
      - **rapidxml/** - Examples integrating RapidXML parser with network library.
      - **rss/** - Examples demonstrating RSS feed parsing and processing.
    - **experiment/** - Experimental and under-development features.
      - **utils/** - Experimental utility implementations.
        - **iterators/** - Experimental iterator implementations.
    - **src/** - Implementation source files for the network library.
      - **uri/** - Source code for URI parsing and manipulation.
    - **test/** - Comprehensive test suite for the network library.
      - **http/** - Unit and integration tests for HTTP functionality.
      - **server/** - Tests for server implementations.
        - **cgi-bin/** - CGI scripts used in server testing.
      - **uri/** - Unit tests for URI parsing and manipulation.

## Key Components

### Boost Headers (`boost/`)
The `boost/` directory contains all the header files that users include in their code. It follows the boost namespace convention and provides:
- Network protocol implementations (HTTP)
- Message types and manipulation
- URI handling
- Utility functions

### Dependencies (`deps/`)
Third-party libraries required by cpp-netlib:
- **asio**: Cross-platform asynchronous I/O
- **cxxopts**: Command-line option parsing
- **googletest/googlemock**: Testing frameworks

### Libraries (`libs/`)
Implementation source code, tests, examples, and documentation:
- **libs/mime**: MIME type handling
- **libs/network**: Core network library with comprehensive test suite

## Building the Project

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make test
```

See the main [README.rst](README.rst) for detailed build instructions.

## Documentation

- **Main README**: [README.rst](README.rst)
- **Online Documentation**: http://cpp-netlib.org/
- **API Reference**: libs/network/doc/
- **Examples**: libs/network/example/

## Testing

The test suite is located in `libs/network/test/` and includes:
- Unit tests for all components
- Integration tests
- HTTP client/server tests
- URI parsing tests

Run tests with:
```bash
make test
```

## Contributing

Please see the main README.rst for:
- Development guidelines
- Coding style guide
- Pull request process
- Contact information

## License

cpp-netlib is licensed under the Boost Software License 1.0.
See [LICENSE_1_0.txt](LICENSE_1_0.txt) for details.

---

*Last updated: Generated automatically as part of comprehensive documentation initiative*
