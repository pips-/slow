#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char		buffer;
	size_t		nread;
	useconds_t	useconds = 1000000; // default 1 second

	if (argc == 2) {
		useconds = atoi(argv[1]);
	}

	while((nread = fread(&buffer, 1, sizeof buffer, stdin)) > 0) {
		usleep(useconds);
		fwrite(&buffer, 1, nread, stdout);
	}

	return 0;
}
