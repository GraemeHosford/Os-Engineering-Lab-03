#include "types.h"
#include "user.h"

int main() {
	// Start tracing system calls
	trace(1);

	// Make a system call to increment number
	getpid();

	printf(1, "System calls made: %d\n", trace(0));

	exit();
}
