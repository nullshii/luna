#include "logger.h"
#include "assert.h"
#include "core/asserts.h"
#include "core/logger.h"
#include "platform/platform.h"

// TODO(nullshii): remove this temporary includes and implement platform specific log
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <vadefs.h>

#define MESSAGE_LENGTH 32000

b8 initialize_logging()
{
	// TODO(nullshii): create log file
	return TRUE;
}

void shutdown_logging()
{
	// TODO(nullshii): cleanup logging/write queued entries
}

void log_output(log_level level, const char* message, ...)
{
	const char* level_strings[] = { "[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: " };
	b8 is_error = level < LOG_LEVEL_WARN;

	// ! Don't do that
	char out_message[MESSAGE_LENGTH];
	memset(out_message, 0, sizeof(out_message));

	char actual_out_message[MESSAGE_LENGTH + 10];
	memset(actual_out_message, 0, sizeof(actual_out_message));

	// Format message
	va_list arg_ptr;
	va_start(arg_ptr, message);
	vsprintf_s(out_message, sizeof(out_message), message, arg_ptr);
	va_end(arg_ptr);

	sprintf_s(actual_out_message, sizeof(actual_out_message), "%s%s\n", level_strings[level], out_message);

	if (is_error)
		platform_console_write_error(actual_out_message, level);
	else
		platform_console_write(actual_out_message, level);
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
	log_output(LOG_LEVEL_FATAL, "Assertion failure: %s, message: %s, in file: %s, line: %i\n", expression, message, file, line);
}