#pragma once

#include "../../platform.hpp"

typedef enum LogLevel {
    LOG_LEVEL_EMERGENCY = 0,
    LOG_LEVEL_ALERT = 1,
    LOG_LEVEL_CRITICAL = 2,
    LOG_LEVEL_ERROR = 3,
    LOG_LEVEL_WARNING = 4,
    LOG_LEVEL_NOTIFICATION = 5,
    LOG_LEVEL_INFORMATION = 6,
    LOG_LEVEL_DEBUG = 7,
    LOG_LEVEL_DEBUG_CODE_EXECUTION = 8
} LogLevel;

bool8 initialize_logging();
void shutdown_logging();

LIBEXP void log_output(LogLevel level, const char *message, ...);

//#################################################################################
// LOG MACROS.
//#################################################################################

// Logs a Fatal-Level Message.
#define LEMERGENCY(message, ...) log_output(LOG_LEVEL_EMERGENCY, message, __VA_ARGS__);
#define LALERT(message, ...) log_output(LOG_LEVEL_ALERT, message, __VA_ARGS__);
#define LCRITICAL(message, ...) log_output(LOG_LEVEL_CRITICAL, message, __VA_ARGS__);
#define LERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, __VA_ARGS__);
#define LWARNING(message, ...) log_output(LOG_LEVEL_WARNING, message, __VA_ARGS__);
#define LNOTIFICATION(message, ...) log_output(LOG_LEVEL_NOTIFICATION, message, __VA_ARGS__);
#define LINFORMATION(message, ...) log_output(LOG_LEVEL_INFORMATION, message, __VA_ARGS__);
#define LDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, __VA_ARGS__);
#define LDEBUG_CODE_EXECUTION(message, ...) log_output(LOG_LEVEL_DEBUG_CODE_EXECUTION, message, __VA_ARGS__);

//#################################################################################
// PLATFORM SPECIFIC CONSOLE WRITERS.
//#################################################################################

LIBEXP void platform_console_write(const char* message, u8 colour);
LIBEXP void platform_console_write_error(const char* message, u8 colour);