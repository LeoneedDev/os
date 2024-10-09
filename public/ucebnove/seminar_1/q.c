#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

main() {
	int p[2];

	if (pipe(p) == -1) {
		fprintf(stderr, "Error: 'pipe': %s\n", strerror(errno));
		exit(1);
	}

	switch (fork()) {
		case -1:
			fprintf(stderr, "Error: 'fork': %s\n", strerror(errno));
			exit(1);
		case 0:
			close(1);
			dup(p[1]);
			close(p[0]);
			close(p[1]);

			execlp("who", "who", NULL);
			fprintf(stderr, "Error: 'exec: file': %s\n", strerror(errno));
			exit(1);
		default:
			close(0);
			dup(p[0]);
			close(p[0]);
			close(p[1]);

			execlp("wc", "wc", "-l", NULL);
			fprintf(stderr, "Error: 'exec: file': %s\n", strerror(errno));
			exit(1);
	}
}
