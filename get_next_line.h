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
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_read(int fd, char *everything);
char	*g_line(char *s);
char	*delline(char *line, char *everything);
char	*get_next_line(int fd);
char	*ft_strchr(char *str);
char	*ft_strdup(char *s1);
char	*send_join(char *s1, char *s2);

#endif
