# Santa Greeting Quickstart Guide

This guide demonstrates how to use the Santa greeting feature in cpp-netlib applications.

## Basic Usage

### Including the Header

Include the Santa greeting header in your C++ source files:

```cpp
#include <boost/network/santa_greeting.hpp>
```

### Simple Example

```cpp
#include <boost/network/santa_greeting.hpp>
#include <iostream>

int main() {
    // Print the Santa greeting
    boost::network::print_santa_greeting();
    
    // Or get the greeting as a string
    std::string greeting = boost::network::santa_greeting();
    std::cout << "The greeting is: " << greeting << std::endl;
    
    return 0;
}
```

### Using with Prefix

You can add a prefix to the Santa greeting:

```cpp
#include <boost/network/santa_greeting.hpp>
#include <iostream>

int main() {
    std::string greeting = boost::network::santa_greeting_with_prefix("INFO");
    std::cout << greeting << std::endl;  // Outputs: INFO: Hi Santa
    
    return 0;
}
```

## Integration with Applications

### Server Applications

Add the Santa greeting to your server startup:

```cpp
#include <boost/network/protocol/http/server.hpp>
#include <boost/network/santa_greeting.hpp>

int main(int argc, char *argv[]) {
    // Print greeting at startup
    boost::network::print_santa_greeting();
    
    // Your server initialization code here
    // ...
    
    return 0;
}
```

### Client Applications

Add the Santa greeting to your client applications:

```cpp
#include <boost/network/protocol/http/client.hpp>
#include <boost/network/santa_greeting.hpp>

int main(int argc, char *argv[]) {
    // Print greeting at startup
    boost::network::print_santa_greeting();
    
    // Your client code here
    // ...
    
    return 0;
}
```

## CLI Help Text

Include the Santa greeting in your help text:

```cpp
if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
    std::cerr << boost::network::santa_greeting() << std::endl;
    return 1;
}
```

## Running Tests

To run the Santa greeting tests:

```bash
cd build
./tests/cpp-netlib-santa_greeting_test
```

## Configuration

The Santa greeting can be configured via `.santa.yml`:

```yaml
santa:
  enabled: true
  custom_message: "Hi Santa"
  show_in_logs: true
```

## API Reference

### Functions

- `std::string santa_greeting()` - Returns "Hi Santa"
- `void print_santa_greeting()` - Prints "Hi Santa" to stdout
- `std::string santa_greeting_with_prefix(const std::string& prefix)` - Returns greeting with prefix

## Examples

Full examples using the Santa greeting feature can be found in:

- `libs/network/example/http/hello_world_server.cpp`
- `libs/network/example/http/hello_world_client.cpp`
- `libs/network/example/simple_wget.cpp`

## Support

For more information, see the main `SANTA.md` documentation.
