#include "defines.h"
#include <core/asserts.h>
#include <core/logger.h>

// ! Temporary
#include <platform/platform.h>

int main()
{
	LFATAL("Pi is: %f", 3.14f);
	LERROR("Pi is: %f", 3.14f);
	LWARN("Pi is: %f", 3.14f);
	LDEBUG("Pi is: %f", 3.14f);
	LTRACE("Pi is: %f", 3.14f);

	// LASSERT(TRUE);
	// LASSERT_MSG(FALSE, "BOBA");

	platform_state state;
	if (platform_startup(&state, "Luna Engine", 20, 20, 1280, 720))
	{
		while (TRUE)
		{
			platform_pump_message(&state);
		}
	}
	platform_shutdown(&state);

	return 0;
}