# Dependencies Directory

## Description

This directory contains external dependencies required by the C++ Network Library. These are third-party libraries that the project depends on.

## Contents

- `asio/` - Asynchronous I/O library
- `cxxopts/` - Command line option parsing library
- `googlemock/` - Google Mock testing framework
- `googletest/` - Google Test testing framework

## Usage

These dependencies are typically managed as git submodules or vendored copies. They are automatically included in the build process when you build the cpp-netlib project using CMake.

To initialize and update submodules:

```bash
git submodule init
git submodule update
```
