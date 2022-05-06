

#include "get_next_line.h"
#include <fcntl.h>


int main() {
	int fd;
	char* line;

	fd = open("./test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);

	return 0;
}
