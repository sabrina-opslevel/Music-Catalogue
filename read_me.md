# C++ Network Library

Modern C++ network programming libraries.

## Installation

### Download

Official releases: http://github.com/cpp-netlib/cpp-netlib/downloads

Clone with submodules:
```bash
git clone https://github.com/cpp-netlib/cpp-netlib
cd cpp-netlib
git submodule init
git submodule update
```

### Build Requirements

- CMake 2.8+
- Compiler: GCC 4.x, Clang 3.6, or MSVC 2008
- OpenSSL headers (optional)

### Build Steps

1. Create build directory:
   ```bash
   mkdir ~/cpp-netlib-build && cd ~/cpp-netlib-build
   ```

2. Configure:
   ```bash
   cmake -DCMAKE_BUILD_TYPE=Debug \
         -DCMAKE_C_COMPILER=clang \
         -DCMAKE_CXX_COMPILER=clang++ \
         ~/cpp-netlib
   ```

3. Build and test:
   ```bash
   make
   make test
   ```

## Features

- Common message type for data exchange
- Network protocol message parsers
- STL-friendly adapters and wrappers
- Client and server implementations

## Contributing

Fork the repository and submit pull requests following the [GitHub flow](http://github.com/cpp-netlib/cpp-netlib).

Read the style guide at http://cpp-netlib.org/style-guide.html.

## License

Released under the [Boost Software License](http://boost.org/LICENSE_1_0.txt).

## Support

- Slack: http://slack.cpp-netlib.org/
- Mailing list: https://groups.google.com/forum/#!forum/cpp-netlib
- Issues: http://github.com/cpp-netlib/cpp-netlib/issues

Maintainers:
- Dean Michael Berris (dberris@google.com)
- Glyn Matthews (glyn.matthews@gmail.com)
