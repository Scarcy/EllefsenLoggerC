# Ellefsen Logger

## Description
Ellefsen Logger is a simple, yet effective logging library written in C. It allows for configurable log levels and supports output to both standard output (stdout) and files. The library provides an easy-to-use interface for logging messages with different severity levels, such as DEBUG, INFO, WARN, ERROR, and FATAL.

## Features
- Multiple log levels: DEBUG, INFO, WARN, ERROR, FATAL.
- Configurable output options: stdout and file logging.
- Support for printf-style message formatting.
- Optional date inclusion in log messages.

## Installation
To use the Ellefsen Logger in your project, include the `logger.h` and `logger.c` files in your project directory.

## Usage

### Initialization
First, initialize the logger with the desired log level and output mask:

```c
#include "logger.h"

logger_t* my_logger = logger_init(LOG_INFO, LOG_STDOUT | LOG_FILE);
```

### Logging Messages
To log messages, use the `logger_log` function with the appropriate log level and message format:

```c
logger_log(my_logger, LOG_INFO, "This is an %s message with number %d", "info", 1);
```

### Configuration Options
- `LOG_STDOUT`: Log messages to standard output.
- `LOG_FILE`: Log messages to a file. Ensure you initialize the file pointer in the logger struct.
- `NO_DATE`: Do not include the date in log messages.

### Cleanup
When finished, clean up the logger to free allocated resources:

```c
logger_destroy(my_logger);
```

## Contributing
Contributions to Ellefsen Logger are welcome. Please feel free to submit pull requests or report any issues you encounter.

## License
Specify your license here.

```
