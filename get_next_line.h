/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:51:15 by rrakman           #+#    #+#             */
/*   Updated: 2023/02/07 22:51:15 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);
char *ft_findnewline(char *s);
char *ft_readfile(int fd,  char *kolchi);
char	*getfline(char *s);
char *delfline(char *line, char *kolchi);
char *get_next_line(int fd);
//char	*ft_strdup(char *s1);
//char    *send_join(char *s1, char *s2);

#endif
