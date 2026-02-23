# Libraries Directory

## Description

This directory contains the implementation source files for the C++ Network Library. It includes the core library implementations for network protocols and MIME handling.

## Contents

- `network/` - Network protocol implementations including HTTP client/server
- `mime/` - MIME type detection and handling implementations

## Usage

The libraries in this directory are built as part of the cpp-netlib build process. To build the libraries:

```bash
mkdir build
cd build
cmake ..
make
```

After building, the resulting libraries can be linked against your applications. The source files in this directory provide the implementation for the headers found in the `boost/` directory.
