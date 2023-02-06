#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i])
        i++;
    return(i);
}
char *ft_strjoin(char *s1, char *s2)
{
    int i,j;
    char *str;

    i = 0;
    j = 0;
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (0);
    if(s1)
    {    
        while(s1[i])
        {
            str[i] = s1[i];
            i++;
        }
        free(s1);
    }
    while(s2[j])
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = 0;
    return (str);
}



