#include "../include/logger.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARGS 10

void logger_stdout(char *debug_print);
void logger_file(FILE *fd, char *debug_print);

logger_t *logger_init(enum log_level level, uint32_t log_output_mask) {
  if (log_output_mask == 0) {
    printf("No log output mask provided\n");
    return NULL;
  }
  logger_t *logger = (logger_t *)malloc(sizeof(logger_t));
  if (logger == NULL) {
    printf("Failed to allocate memory for logger\n");
    return NULL;
  }
  logger->mask = log_output_mask;
  logger->level = level;
  return logger;
}

void logger_log(logger_t *logger, enum log_level level, const char *format,
                ...) {
  if (logger == NULL || level < logger->level) {
    return;
  }

  char log_str[256]; // Ensure this buffer is large enough
  log_str[0] = '\0'; // Initialize as an empty string

  // Append log level string
  const char *level_str[] = {"[DEBUG]", "[INFO]", "[WARN]", "[ERROR]",
                             "[FATAL]"};
  strcat(log_str, level_str[level]);
  strcat(log_str, " ");

  // Append date if NO_DATE is not set
  if (!(logger->mask & NO_DATE)) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char date_str[64];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", tm);
    strcat(log_str, date_str);
    strcat(log_str, " ");
  }

  // Format the main message
  va_list args;
  va_start(args, format);
  char msg[256];
  vsnprintf(msg, sizeof(msg), format, args);
  va_end(args);

  strcat(log_str, msg);

  // Log to stdout if LOG_STDOUT is set
  if (logger->mask & LOG_STDOUT) {
    printf("%s\n", log_str);
  }
  // Add similar conditions for LOG_STDERR and LOG_FILE
}

void logger_destroy(logger_t *logger) {
  if (logger == NULL) {
    printf("Logger not initialized\n");
    return;
  }
  free(logger);
}
void logger_stdout(char *format) { printf("%s", format); }

void logger_file(FILE *fd, char *debug_print) { return; }
