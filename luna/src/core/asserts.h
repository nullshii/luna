#pragma once

#include "defines.h"

#define LASSERTIONS_ENABLED

#ifdef LASSERTIONS_ENABLED

#if _MSC_VER
#include <intrin.h>
#define debugbreak() __debugbreak()
#else
#define debugbreak() __builtin_trap()
#endif

LAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define LASSERT(expression)                                                         \
	{                                                                               \
		if (expression)                                                             \
			{                                                                       \
			}                                                                       \
		else                                                                        \
			{                                                                       \
				report_assertion_failure(#expression, "empty", __FILE__, __LINE__); \
				debugbreak();                                                       \
			}                                                                       \
	}

#define LASSERT_MSG(expression, message)                                            \
	{                                                                               \
		if (expression)                                                             \
			{                                                                       \
			}                                                                       \
		else                                                                        \
			{                                                                       \
				report_assertion_failure(#expression, message, __FILE__, __LINE__); \
				debugbreak();                                                       \
			}                                                                       \
	}

#ifdef LUNA_BUILD_MODE_DEBUG
#define LASSERT_DEBUG(expression)                                                   \
	{                                                                               \
		if (expression)                                                             \
			{                                                                       \
			}                                                                       \
		else                                                                        \
			{                                                                       \
				report_assertion_failure(#expression, "empty", __FILE__, __LINE__); \
				debugbreak();                                                       \
			}                                                                       \
	}
#else
#define LASSERT_DEBUG(expression)
#endif

#else

#define LASSERT(expression)
#define LASSERT_MSG(expression, message)
#define LASSERT_DEBUG(expression)

#endif