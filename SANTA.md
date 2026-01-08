# Santa Greeting Feature

## Overview

The Santa greeting feature provides a standardized "Hi Santa" greeting mechanism across all organization repositories. This implementation is repository-agnostic, allowing for consistent Santa greetings regardless of technology stack, programming language, or project type.

## Purpose

The Santa greeting feature serves multiple purposes:

- **Consistency**: Provides a uniform greeting mechanism across all projects
- **Visibility**: Makes the greeting visible in logs, CLI outputs, and build processes
- **Testability**: Includes comprehensive test coverage to ensure reliability
- **Configurability**: Can be customized via configuration files

## Implementation Details

### Header File

The core implementation is provided in `boost/network/santa_greeting.hpp`, which contains:

- `santa_greeting()` - Returns the greeting string "Hi Santa"
- `print_santa_greeting()` - Prints the greeting to standard output

### Configuration

The `.santa.yml` configuration file allows customization of the Santa greeting feature:

- `enabled`: Toggle the feature on/off
- `custom_message`: Optional custom greeting message
- `show_in_logs`: Control visibility in application logs

### Usage

Include the Santa greeting in your C++ applications:

```cpp
#include <boost/network/santa_greeting.hpp>

int main() {
    boost::network::print_santa_greeting();
    // Your application code here
    return 0;
}
```

### Testing

Unit tests are provided in `libs/network/test/santa_greeting_test.cpp` to verify the Santa greeting functionality.

## Integration Points

The Santa greeting is integrated into:

1. Application startup sequences (see examples)
2. CLI help text and welcome messages
3. Build logs and CI/CD pipeline output
4. Project documentation and quickstart guides

## Configuration Reference

Example `.santa.yml` configuration:

```yaml
santa:
  enabled: true
  custom_message: "Hi Santa"
  show_in_logs: true
```

## Support

For questions or issues related to the Santa greeting feature, please file an issue in the project repository.
