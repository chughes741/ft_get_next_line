

#include "get_next_line.h"
#include <fcntl.h>


int main() {
	char *line;

	int fd = open("./test.txt", O_RDONLY);
	for (int i = 0; i < 2; ++i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);

	return 0;
}