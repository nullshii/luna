#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED
#define LOG_INFO_ENABLED
#define LOG_DEBUG_ENABLED
#define LOG_TRACE_ENABLED

#ifdef LUNA_BUILD_MODE_RELEASE
#undef LOG_DEBUG_ENABLED
#undef LOG_TRACE_ENABLED
#endif

typedef enum log_level
{
	LOG_LEVEL_FATAL,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_WARN,
	LOG_LEVEL_INFO,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_TRACE,
} log_level;

LAPI b8 initialize_logging();
LAPI void shutdown_logging();

LAPI void log_output(log_level level, const char* message, ...);

#define LFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

#ifndef LERROR
#define LERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)
#endif

#ifdef LOG_WARN_ENABLED
#define LWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
#define LWARN(message, ...)
#endif

#ifdef LOG_INFO_ENABLED
#define LINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
#define LINFO(message, ...)
#endif

#ifdef LOG_DEBUG_ENABLED
#define LDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
#define LDEBUG(message, ...)
#endif

#ifdef LOG_TRACE_ENABLED
#define LTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
#define LTRACE(message, ...)
#endif