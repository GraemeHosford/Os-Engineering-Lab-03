#include "types.h"
#include "user.h"
#include "uproc.h"

int main() {
	const int MAX_PROCS = 10;
	struct uproc *proctable = malloc(sizeof(struct uproc) * MAX_PROCS);

	if (proctable == 0) {
		printf(1, "Not able to create process table\n");
		exit();
	}

	int processes = getprocs(MAX_PROCS, proctable);

	if (processes < 1) {
		printf(1, "Error getting processes\n");
		free(proctable);
		exit();
	}

	struct uproc *uproc = &proctable[0];

	printf(1, "PID    PPID      State       Size       Name\n");
	/* No reason to show unused processes as all values are zeroed out anyway */
	while (uproc != &proctable[MAX_PROCS- 1] && uproc-> state != 0) {
		printf(1, " %d      %d        ", uproc->pid, uproc->ppid);

		if (uproc->state == 1) {
			printf(1, "EMBRYO");
		} else if (uproc->state == 2) {
			printf(1, "SLEEPING");
		} else if (uproc->state == 3) {
			printf(1, "RUNNABLE");
		} else if (uproc->state == 4) {
			printf(1, "RUNNING");
		} else if (uproc->state == 5) {
			printf(1, "ZOMBIE");
		}

		printf(1, "    %d      %s\n", uproc->sz, uproc->name);
		uproc++;
	}

	free(proctable);
	exit();
}
