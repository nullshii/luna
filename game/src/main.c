#include "defines.h"
#include <core/asserts.h>
#include <core/logger.h>

int main()
{
	LFATAL("Pi is: %f", 3.14f);
	LERROR("Pi is: %f", 3.14f);
	LWARN("Pi is: %f", 3.14f);
	LDEBUG("Pi is: %f", 3.14f);
	LTRACE("Pi is: %f", 3.14f);

	LASSERT(TRUE);
	LASSERT_MSG(FALSE, "BOBA");

	return 0;
}