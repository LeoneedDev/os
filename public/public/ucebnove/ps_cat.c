#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ps_print(fmt, ...) dprintf(STDOUT_FILENO, fmt, ## __VA_ARGS__)

int main(int argc, const char *argv[])
{
	const char *filename;
	ssize_t data_size;
	char buf[1024];
	int fd;

	int i = 1;
	do {
		if (argc == 1 || !strcmp(argv[i], "-")) {
			filename = "/dev/stdin";
			fd = STDIN_FILENO;
		} else {
			filename = argv[i];
			assert((fd = open(filename, O_RDONLY)) >= 0);
		}

		ps_print("Reading file '%s'\n", filename);
		ps_print("================================================\n");
		while ((data_size = read(fd, buf, sizeof(buf)))) {
			assert(data_size >= 0);
			assert(write(STDOUT_FILENO, buf, data_size) >= 0);
		}
		ps_print("================================================\n\n");
	} while (++i < argc);

	return 0;
}

