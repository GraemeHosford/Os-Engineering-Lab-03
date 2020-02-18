#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf(1, "You must include the source and destination arguments when using the mv command\n");
		printf(1, "Use like mv [source file] [destination file]\n");
	exit();
	}

	char *src = argv[1];
	char *dest = argv[2];

	int linkRetVal = link(src, dest);
	int unlinkRetVal = unlink(src);

	if (linkRetVal < 0 || unlinkRetVal < 0) {
		printf(1, "mv command has failed\n");
		exit();
	}

	exit();
}
