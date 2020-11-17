# include <stdio.h>
# include <fcntl.h>
#include "get_next_line.h"

int main (void)
{
	char	*line;
	int		fd1, fd2, fd3, fd5;
	
	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	fd5 = open("text5.txt", O_RDONLY);
	
	
	printf("%d\n", get_next_line(42, &line));
	printf("%s\n\n", line);
	//free(line);
	
	printf("%d\n", get_next_line(fd1, &line));
	printf("%s\n\n", line);
	free(line);

	printf("%d\n", get_next_line(fd2, &line));
	printf("%s\n\n", line);
	free(line);

	printf("%d\n", get_next_line(fd3, &line));
	printf("%s\n\n", line);
	free(line);
	
	printf("%d\n", get_next_line(0, &line));
	printf("%s\n\n", line);
	free(line);
	
	printf("%d\n", get_next_line(0, &line));
	printf("%s\n\n", line);
	free(line);
	
	printf("%d\n", get_next_line(fd1, &line));
	printf("%s\n\n", line);
	free(line);

	printf("%d\n", get_next_line(fd1, &line));
	printf("%s\n\n", line);
	free(line);
	
	printf("%d\n", get_next_line(fd1, &line));
	printf("%s\n\n", line);
	free(line);
	
	printf("%d\n", get_next_line(fd1, &line));
	printf("%s\n\n", line);
	free(line);
	
	printf("%d\n", get_next_line(fd5, &line));
	printf("%s\n\n", line);
	free(line);
	
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd5);
	
	while (1)
	{}
	
	return (0);
}
