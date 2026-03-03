# Hello Message Standard

## Overview

This document defines the standardized "hello" greeting mechanism for cpp-netlib and serves as a reference for implementing similar functionality across organization repositories.

## Purpose

The hello message standard provides:
- A consistent way to identify the application and its version
- A customizable greeting mechanism for different deployment environments
- Standard endpoints for API health checks and status pages
- Easy integration testing and monitoring capabilities

## Implementation Details

### 1. Core Functionality

The hello message functionality is implemented in the `boost/network/hello.hpp` header file and provides:

```cpp
// Get basic hello message
std::string get_hello_message();

// Get hello message with version information
std::string get_hello_message_with_version();
```

### 2. Configuration

The hello message can be customized using the `CPPNETLIB_HELLO_MESSAGE` environment variable:

```bash
export CPPNETLIB_HELLO_MESSAGE="Custom greeting"
```

If not set, the default message is: `"Hello from cpp-netlib!"`

### 3. Default Behavior

- **Default Message**: "Hello from cpp-netlib!"
- **Version Format**: "{message} (version {version_number})"
- **Environment Variable**: `CPPNETLIB_HELLO_MESSAGE`
- **Configuration File**: `.hello.conf` (documentation purposes)

### 4. API Endpoints

For HTTP-based services, the following standard endpoints should be implemented:

#### GET /hello
Returns the hello message with version information.

**Response:**
- Status: 200 OK
- Content-Type: text/plain
- Body: Hello message with version

**Example:**
```
Hello from cpp-netlib! (version 0.12.0)
```

#### GET /health
Returns health status with hello message.

**Response:**
- Status: 200 OK
- Content-Type: text/plain
- Body: "OK - {hello_message}"

**Example:**
```
OK - Hello from cpp-netlib!
```

### 5. Command-Line Tools

Command-line applications should:
- Print hello message on startup (when appropriate)
- Provide a `--version` flag that includes the hello message
- Support `CPPNETLIB_HELLO_MESSAGE` environment variable

### 6. Testing

Unit tests must verify:
- Default message is returned when no environment variable is set
- Custom message is returned when environment variable is set
- Version information is included in version message
- Empty environment variable falls back to default

See `libs/network/test/hello_test.cpp` for reference implementation.

### 7. CI/CD Integration

Build pipelines should verify:
- Hello message binaries/executables are built successfully
- Hello message outputs expected format
- Tests pass for hello functionality

Example CI checks:
```bash
# Verify binary exists
test -f build/example/hello_message

# Verify output contains hello
./hello_message | grep -i "hello"
```

### 8. Documentation Requirements

Projects implementing the hello standard must document:
- How to customize the hello message
- Available API endpoints (if applicable)
- Command-line usage examples
- Environment variable configuration

This should be included in the main README file.

## Usage Examples

### Basic Usage

```cpp
#include <boost/network/hello.hpp>
#include <iostream>

int main() {
    std::cout << boost::network::get_hello_message() << std::endl;
    return 0;
}
```

### With Custom Message

```bash
CPPNETLIB_HELLO_MESSAGE="Welcome!" ./my_application
```

### HTTP Server

```cpp
#include <boost/network/protocol/http/server.hpp>
#include <boost/network/hello.hpp>

// In request handler:
if (path == "/hello") {
    std::string msg = boost::network::get_hello_message_with_version();
    connection->write(msg);
}
```

## Benefits

1. **Consistency**: Standardized approach across all repositories
2. **Monitoring**: Easy health check and status verification
3. **Debugging**: Quick identification of service version and status
4. **Testing**: Simple integration test verification
5. **Customization**: Environment-specific messages without code changes

## Future Enhancements

Potential future improvements to the standard:
- JSON format option for API responses
- Additional metadata (build time, git commit, etc.)
- Internationalization support
- Structured logging integration

## Compliance

To be compliant with this standard, implementations must:
- ✓ Provide a hello message function/method
- ✓ Support environment variable configuration
- ✓ Include version information option
- ✓ Implement /hello endpoint (for API services)
- ✓ Include unit tests
- ✓ Document in README
- ✓ Verify in CI/CD pipeline

## References

- Implementation: `boost/network/hello.hpp`
- Tests: `libs/network/test/hello_test.cpp`
- Examples: `libs/network/example/hello_message.cpp`, `libs/network/example/http/hello_endpoint_server.cpp`
- Configuration: `.hello.conf`
- API Specification: `swagger.yml` (paths: /hello, /health)
