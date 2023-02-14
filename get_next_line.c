/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:49:19 by rrakman           #+#    #+#             */
/*   Updated: 2023/02/07 22:49:19 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *kolchi)
{
	char	*buff;
	ssize_t	bytes;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(kolchi))
	{
		bytes = read (fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			free (kolchi);
			return (NULL);
		}
		buff[bytes] = '\0';
		kolchi = send_join(kolchi, buff);
	}
	free (buff);
	return (kolchi);
}

char	*getfline(char *s)
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

char	*delfline(char *line, char *kolchi)
{
	int		len;
	int		lenfl;
	char	*chyata;

	len = ft_strlen(kolchi);
	lenfl = ft_strlen(line);
	chyata = malloc ((len - lenfl) + 1);
	if (!chyata)
		return (0);
	len = 0;
	while (kolchi[lenfl])
	{
		chyata[len] = kolchi[lenfl];
		lenfl++;
		len++;
	}
	chyata[len] = 0;
	free (kolchi);
	return (chyata);
}

char	*get_next_line(int fd)
{
	static char	*kolchi;
	char		*line;

	line = 0;
	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	kolchi = ft_readline(fd, kolchi);
	if (ft_strlen(kolchi) > 0)
	{
		line = getfline(kolchi);
		kolchi = delfline(line, kolchi);
		if (ft_strlen(kolchi) == 0)
		{
			free(kolchi);
			kolchi = 0;
		}
	}
	else if (ft_strlen(kolchi) == 0)
	{
		free(kolchi);
		kolchi = 0;
	}
	return (line);
}

// int main ()
// {
// 	char *p;
// 	int fd = open("file.txt", O_RDWR , 0777);
// 	for(int i = 0; i < 4 ; i++)
// 	{
// 		p = get_next_line(fd);
// 		printf("%s", p);
// 		free(p);
// 	}
// 	sleep(100);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }