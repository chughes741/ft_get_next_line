

#include "get_next_line.h"
#include <fcntl.h>


int main() {
	int fd;
	fd = open("./test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
}