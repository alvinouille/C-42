/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:45:58 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/02 10:11:00 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*protection(char *keep)
{
	free(keep);
	return (NULL);
}

char	*ft_strjoin_modif(char *keep, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!keep)
	{
		keep = malloc(1);
		if (!keep)
			return (NULL);
		keep[0] = '\0';
	}
	if (!buff)
		return (protection(keep));
	str = malloc(ft_strlen(keep) + ft_strlen(buff) + 1);
	if (!str)
		return (protection(keep));
	while (keep[++i])
		str[i] = keep[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(keep) + ft_strlen(buff)] = '\0';
	free(keep);
	return (str);
}

char	*loopin(int fd, char **keep)
{
	char		*buff;
	size_t		size;

	buff = malloc((BUFFER_SIZE + 1));
	if (!buff)
	{
		if (*keep)
			free(*keep);
		return (NULL);
	}
	size = 1;
	while (!ft_strchr((*keep), '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == (size_t) - 1)
		{
			free(*keep);
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		(*keep) = ft_strjoin_modif((*keep), buff);
	}
	free(buff);
	return (*keep);
}

char	*get_next_line(int fd, int flag)
{
	char		*line;
	static char	*keep;

	if (flag == 1)
	{
		if (keep)
			free(keep);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (loopin(fd, &keep))
	{
		line = ft_line(keep);
		if (!line)
		{
			free(keep);
			return (NULL);
		}
		keep = ft_keep_memory(keep);
		return (line);
	}
	else
		return (NULL);
}
