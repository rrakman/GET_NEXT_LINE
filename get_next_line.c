#include "get_next_line.h"

char *ft_findnewline(char *s)
{
	int counter = 0;
	if (!s)
		return(0);
	while(s[counter] != '\n' && s[counter])
	{
		if(s[counter] == '\n')
			return (s + counter);
		counter++;
	}
	return (0);
}

char *ft_readfile(int fd, char *buff, char *kolchi)
{
	int bytes;
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return(0);
	while(!ft_findnewline(kolchi))
	{
		bytes = read(fd,buff,BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buff[bytes] = '\0';
		kolchi = ft_strjoin(kolchi,buff);
		
	}
	free(buff);
	return(kolchi);
}

char	*getfline(char *s)
{
	int	i;	
	char *new;
	
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return(0);
	
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		new[i] = s[i];
		new[i + 1] = 0;
		i++;
	}
	if (s[i] == '\n')
		new[i++] = '\n';
	new[i] = 0;
	return(new);
}

char *delfline(char *line, char *kolchi)
{
	int len = ft_strlen(kolchi);
	int lenfl = ft_strlen(line);
	char *chyata;
	chyata = malloc ((len - lenfl) + 1);
	if (!chyata)
		return(0);
	len = 0;
	while(kolchi[lenfl])
	{
		chyata[len] = kolchi[lenfl];
		lenfl++;
		len++;
	}
	chyata[len] = 0;
	free(kolchi);
	return(chyata);
}

char *get_next_line(int fd)
{
	static char *kolchi;
	char *line;
	if (fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	line = 0;
	kolchi = ft_readfile(fd,line,kolchi);
	if (ft_strlen(kolchi) > 0)
	{
		line = getfline(kolchi);
		kolchi = delfline(line, kolchi);
	}
	if (ft_strlen(line) == 0)
	{
		if(ft_strlen(kolchi) != 0)
		{
			free(kolchi);
			kolchi = 0;
		}
		return(0);
	}
	return(line);
}

int main ()
{
	int fd = open("file.txt",O_RDWR, 0777);
	char *p;
	//get_next_line(fd);
	for(int i = 0; i < 10 ; i++)
	{
		p = get_next_line(fd);
		printf("%s", p);
		free(p);
	}
	//sleep(100);
}