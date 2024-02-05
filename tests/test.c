#include "../include/logger.h"

int main() {
  logger_t *logger = logger_init(LOG_DEBUG, LOG_STDOUT);

  logger_log(logger, LOG_WARN, "Hello, %s", "world");
}
