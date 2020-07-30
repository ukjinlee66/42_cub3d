#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "he.h"

int main(void)
{
	char *line;
	int ret;
	int fd;

	fd = open("t1.txt", O_RDONLY);
	printf("open success\n");
	while ((ret = get_next_line(fd, &line)))
	{
		printf("ret : %d line : %s\n", ret, line);
		free(line);
	}
	printf("ret : %d line : %s\n", ret, line);
	free(line);
	return (0);
}
