# Music Catalogue

A modern music catalogue management system built with C++ and powered by cpp-netlib networking libraries.

## Overview

Music Catalogue is a comprehensive solution for managing and organizing music collections. It provides a RESTful API for cataloging songs, albums, artists, and playlists.

## Features

- **Artist Management**: Add, update, and browse artists in your catalogue
- **Album Organization**: Manage albums with complete metadata
- **Song Database**: Comprehensive song information and cataloging
- **Playlist Support**: Create and manage custom playlists
- **RESTful API**: Modern HTTP-based API for easy integration
- **Search Functionality**: Quick search across artists, albums, and songs

## Technology Stack

- **C++**: Core application logic
- **cpp-netlib**: Modern C++ network programming libraries for HTTP server/client
- **CMake**: Build system
- **OpenAPI/Swagger**: API documentation and specification

## Prerequisites

- C++ Compiler (GCC 4.x, Clang 3.6, or MSVC 2008)
- CMake version 2.8 or higher
- Boost libraries
- OpenSSL headers (optional, for HTTPS support)

## Building

### Clone the Repository

```bash
git clone https://github.com/your-org/Music-Catalogue
cd Music-Catalogue
git submodule init
git submodule update
```

### Build Instructions

It is recommended to build the project outside of the source directory:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_C_COMPILER=clang \
      -DCMAKE_CXX_COMPILER=clang++ \
      ..
make
```

### Running Tests

```bash
cd build
make test
```

## API Documentation

The API is documented using OpenAPI 3.0 specification. You can view the API documentation by opening `swagger.yml` in the [Swagger Editor](https://editor.swagger.io/).

### Example API Endpoints

- `GET /api/artists` - List all artists
- `GET /api/artists/{id}` - Get artist details
- `POST /api/artists` - Add new artist
- `GET /api/albums` - List all albums
- `GET /api/songs` - List all songs
- `POST /api/playlists` - Create new playlist

## Usage

### Starting the Server

```bash
./music-catalogue-server --port 8080
```

### Example Client Usage

```cpp
#include <boost/network/protocol/http/client.hpp>

using namespace boost::network;
using namespace boost::network::http;

int main() {
    client::request request("http://localhost:8080/api/artists");
    request << header("Connection", "close");
    client client;
    client::response response = client.get(request);
    std::string body = body(response);
    // Process response...
    return 0;
}
```

## Configuration

Configuration options can be set via:
- Command-line arguments
- Configuration file (`config.yml`)
- Environment variables

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

### Development Guidelines

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

Please ensure your code follows the project's coding standards and includes appropriate tests.

## License

This project is released under the Boost Software License. See [LICENSE_1_0.txt](LICENSE_1_0.txt) for details.

## Support

For questions, issues, or feature requests:
- Open an issue on GitHub
- Check the existing documentation
- Review the API specification in `swagger.yml`

## Acknowledgments

Built on top of [cpp-netlib](https://github.com/cpp-netlib/cpp-netlib), a collection of open-source libraries for high level network programming.

## Project Status

[![Build Status](https://travis-ci.org/cpp-netlib/cpp-netlib.svg?branch=master)](https://travis-ci.org/cpp-netlib/cpp-netlib)

---

**Note**: This project leverages the cpp-netlib framework for networking capabilities. For more information about cpp-netlib, see [README.rst](README.rst).
