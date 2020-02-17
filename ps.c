#include "types.h"
#include "stat.h"
#include "user.h"
#include "uproc.h"

int main() {
	const int MAX_PROCS = 10;
	struct uproc proctable[MAX_PROCS];

	getprocs(MAX_PROCS, proctable);

	struct uproc *uproc = &proctable[0];

	printf(1, "PID\tPPID\tState\tName\n");
	while (uproc != proctable[MAX_PROCS- 1]) {
		printf(1, "%d\t%d\t", uproc->pid, uproc->ppid);

		if (p->state == UNUSED) {
			printf(1, "UNUSED");
		} else if (p->state == EMBRYO) {
			printf(1, "EMBRYO");
		} else if (p->state == SLEEPING) {
			printf(1, "SLEEPING");
		} else if (p->state == RUNNABLE) {
			printf(1, "RUNNABLE");
		} else if (p->state == RUNNING) {
			printf(1, "RUNNING");
		} else if (p->state == ZOMBIE) {
			printf(1, "ZOMBIE");
		}

		printf(1, "\t%s\n", uproc->name);
		uproc++;
	}

	exit();
}
