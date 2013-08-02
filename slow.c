#define _XOPEN_SOURCE 500
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char		line[1024];
	int		linesize = sizeof(line);
	int		useconds = 1000000;

	if (argc == 2) {
		useconds = atoi(argv[1]);
	}

	while(fgets(line, linesize, stdin)) {
		usleep(useconds);
		fputs(line, stdout);
	}

	return 0;
}
