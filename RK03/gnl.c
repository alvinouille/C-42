#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int ft_strchr(char *str, char c)
{
    int i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *join(char *keep, char *buf)
{
    int i = 0;
    int j = 0;
    char *str;
    if (!keep)
    {
        keep = malloc(1);
        keep[0] = '\0';
    }
    if (!buf)
        return NULL;
    str = malloc(ft_strlen(*keep) + ft_strlen(buf) + 1);
    while (keep[i])
    {
        str[i] = keep[i];
        i++;
    }
    while (buf[j])
    {
        str[i] = buf[j];
        i++;
        j++;
    }
    str[i] = '\0';
    free(*keep);
    return (str);
}

int looping(char **keep, int fd)
{
    int size = 1;
    char *buf;

    buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (0);
    while (!(ft_strchr(*keep, '\n')) && size != 0)
    {
        size = read(fd, buf, BUFFER_SIZE);
        if (size == -1)
        {
            free(buf);
            return (0);
        }
        buf[size] = '\0';
        *keep = join(keep, buf);
    }
    free(buf);
    return (1);
}

char *ft_line(char *keep)
{
    int i = 0;
    int j = 0;
    char *str;
    if (!keep)
        return (NULL);
    while (keep[i] != '\n' && keep[i])
        i++;
    str = malloc(sizeof(char) * (i + 2));
    i = 0;
    while (keep[i] && keep[i] != '\n')
    {
        str[i] = keep[i];
        i++;
    }
    if (keep[i] == '\n')
        i++;
    str[i] = '\0';
    return (str);
}

char *keep_memory(char **keep)
{
    char *str;
    int i = 0;
    int j = 0;
    if (!*keep)
        return (NULL);
    printf("%s \n", *keep);
    while ((*keep)[i] != '\n' && (*keep)[i])
        i++;
    if (!(*keep)[i])
    {
        free(*keep);
        return (NULL);
    }
    str = malloc(ft_strlen(*keep) - i + 1);
    if ((*keep)[i] == '\n')
        i++;
    while ((*keep)[i])
    {
        str[j] = (*keep)[i];
        i++;
        j++;
    }
    free(*keep);
    return (str);
}

char *get_next_line(int fd)
{
    static char *keep;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (looping(&keep, fd))
    {
        line = ft_line(keep);
        if (!line)
            return (NULL);
        keep = keep_memory(&keep);
        return (line);
    }
    else
        return (NULL);
}

#include<stdio.h>
#include<string.h>

int main()
{
    int fd = open("lol", O_RDONLY);
    char *str;
    while (1)
    {
        str = get_next_line(fd);
        if (!str)
            break;
        printf("%s \n", str);
        free(str);
    }
    free(str);
}