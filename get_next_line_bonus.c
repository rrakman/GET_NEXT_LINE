/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:20:41 by rrakman           #+#    #+#             */
/*   Updated: 2023/02/24 00:36:06 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *everything)
{
	char	*buff;
	ssize_t	bytes;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(everything))
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			free (everything);
			return (NULL);
		}
		buff[bytes] = '\0';
		everything = send_join(everything, buff);
	}
	free (buff);
	return (everything);
}

char	*g_line(char *s)
{
	int		i;	
	char	*new;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc (i + 1);
	if (!new)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		new[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*delline(char *line, char *everything)
{
	int		len;
	int		lenfl;
	char	*rest;

	len = ft_strlen(everything);
	lenfl = ft_strlen(line);
	rest = malloc ((len - lenfl) + 1);
	if (!rest)
		return (0);
	len = 0;
	while (everything[lenfl])
	{
		rest[len] = everything[lenfl];
		lenfl++;
		len++;
	}
	rest[len] = 0;
	free (everything);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*everything[INT_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	everything[fd] = ft_read(fd, everything[fd]);
	if (ft_strlen(everything[fd]) > 0)
	{
		line = g_line(everything[fd]);
		everything[fd] = delline(line, everything[fd]);
		if (ft_strlen(everything[fd]) == 0)
		{
			free(everything[fd]);
			everything[fd] = NULL;
		}
	}
	else
	{
		free(everything[fd]);
		everything[fd] = NULL;
	}
	return (line);
}

// int main ()
// {
// 	char *p,*p2;
// 	int fd = open("file.txt", O_RDWR , 0777);
// 	int fd2 = open("file2.txt", O_RDWR , 0777);
// 	for(int i = 0; i < 9 ; i++)
// 	{
// 		p = get_next_line(fd);
// 		printf("%s", p);
// 		free(p);
// 		p2 = get_next_line(fd2);
// 		printf("%s", p2);
// 		free(p2);
// 	}
// 	//sleep(100);
// }