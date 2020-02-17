#include "types.h"
#include "user.h"

struct uproc {
	int pid;
	int ppid;
	int state;
	uint sz;
	char name[16];
}
