// .TH Logger
#ifndef __ELLEFSEN_LOGGER_H__
#define __ELLEFSEN_LOGGER_H__
/*  logger.h
 *  A simple logger made in C.
 *  By specifying a log level and log output, the logger will print to the specified output.
 *  The logger can be currently used to print to stdout and to a file.
 *  Author: Fredrik Ellefsen
 *  Created on: 2016-02-10
*/
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

#define LOG_STDOUT 0x01
#define LOG_STDERR 0x02
#define LOG_FILE   0x04
#define NO_DATE    0x08

enum log_level {
  LOG_DEBUG,
  LOG_INFO,
  LOG_WARN,
  LOG_ERROR,
  LOG_FATAL
};

// The Centerpiece of the Logger Library.
//
// This struct contains the configuration for the logger.
typedef struct {
  uint32_t mask;
  enum log_level level;
  FILE *file;
} logger_t;


// Initialize logger
// level: Specify the log level. This adds a [LEVEL] prefix to the log message. It will only log messages with a level equal to or higher than the specified level.
// log_output_mask: Bitmask Options to configure the logging output.
// LOG_STDOUT - Log to stdout
//
// LOG_STDERR - Log to stderr (NOT IMPLEMENTED YET)
//
// LOG_FILE   - Log to a file. This requires that you initialize the file pointer in the logger struct.
//
// NO_DATE    - Do not print the date in the log message.
logger_t* logger_init(enum log_level level, uint32_t log_output_mask);

// Send a log message with the specified log level.
//
// The Logger supports printf style formatting with up to 10 arguments.
//
// If the [enum log_level level] is higher than the specified level in the logger, the message will not be logged.
void logger_log(logger_t *logger, enum log_level level, const char *fmt, ...);


#endif
