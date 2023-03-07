############## GET_NEXT_LINE ##############

Reading a line from a fd is way too tedious

#########################################

get_next_line is a function that reads a file descriptor line by line.

Description:

The get_next_line function takes a file descriptor as its first argument and returns a line read from the file descriptor. The function reads the file descriptor one character at a time until it reaches the end of a line, indicated by a newline character, or the end of the file. Subsequent calls to get_next_line with the same file descriptor will continue reading the file from where the previous call left off.

Usage:

To use get_next_line, include the function prototype in your source file:
```
char	*get_next_line(int fd);
```
Example:
```
int main ()
{
	char *p,*p2;
	int fd = open("file.txt", O_RDWR , 0777);
	int fd2 = open("file2.txt", O_RDWR , 0777);
	for(int i = 0; i < 9 ; i++)
	{
		p = get_next_line(fd);
		printf("%s", p);
		free(p);
		p2 = get_next_line(fd2);
		printf("%s", p2);
		free(p2);
	}
}
```
