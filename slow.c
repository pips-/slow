#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "arg.h"

char *argv0;

void usage() {
	printf("usage: %s [-t usec] [-F]\n", argv0);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	char		buffer;
	size_t		nread;
	useconds_t	useconds	= 1000000; // default 1 second
	unsigned int	flush		= 0;

	ARGBEGIN {
	case 't':
		useconds = atoi(EARGF(usage()));
		break;
	case 'F':
		flush = 1;
		break;
	default:
		usage();
	} ARGEND;

	while((nread = fread(&buffer, 1, sizeof buffer, stdin)) > 0) {
		usleep(useconds);
		fwrite(&buffer, 1, nread, stdout);
		if(flush) {
			fflush(stdout);
		}
	}

	return EXIT_SUCCESS;
}
