

#include "get_next_line.h"
#include <fcntl.h>


int main() {
	int fd;
	char *line;


	fd = open("./test.txt", O_RDONLY);

	// printf("%zi\n", read(fd, line, 100));

	// printf("%s\n", line);


	for (int i = 0; i < 10; ++i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

	close(fd);

	return 0;
}