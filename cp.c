#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {

	char *src;
	char *dest;
	char buffer[1024];

	int srcFileOpen, destFileOpen, readRetVal, writeRetVal;

	if (argc != 3) {
		printf(1, "There must be 3 total arguements for the cp command\n");
		printf(1, "Use like this cp [source file] [destination file]\n");
		exit();
	}

	src = argv[1];
	dest = argv[2];

	srcFileOpen = open(src, O_RDONLY);

	if (srcFileOpen < 0) {
		printf(1, "Error with the source file\n");
		exit();
	}

	destFileOpen = open(dest, O_CREATE|O_WRONLY);

	if (destFileOpen < 0) {
		printf(1, "Error with the destination file\n");
		exit();
	}

	while((readRetVal = read(srcFileOpen, buffer, sizeof(buffer))) > 0) {
		writeRetVal = write(destFileOpen, buffer, readRetVal);

		if (writeRetVal < 0) {
			break;
		}
	}

	if (readRetVal < 0 || writeRetVal < 0) {
		printf(1, "Error when trying to copy the file\n");
	}

	exit();
}
