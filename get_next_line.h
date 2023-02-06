#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
char *ft_findnewline(char *s);
char *ft_readfile(int fd, char *buff, char *kolchi);
char	*getfline(char *s);
char *delfline(char *line, char *kolchi);
char *get_next_line(int fd);

#endif
