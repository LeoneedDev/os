#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

main() {
	DIR *d;
	struct dirent *de;

	if ((d = opendir(".")) == NULL) {
		fprintf(stderr, "Error: 'opendir: %s': %s\n", path, strerror(errno));
		exit(1);
	}

	while ((de = readdir(d)) != NULL) {
		printf("%s\n", de->d_name);
	}

	closedir(d);
}
