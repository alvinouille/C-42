/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:45:58 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/03 16:56:33 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_modif(char *keep, char *buff, size_t i, size_t j)
{
	char	*str;

	if (!keep)
	{
		keep = malloc(1);
		if (!keep)
			return (NULL);
		keep[0] = '\0';
	}
	if (!buff)
		return (free(keep), NULL);
	str = malloc(ft_strlen(keep) + ft_strlen(buff) + 1);
	if (!str)
		return (free(keep), NULL);
	while (keep[++i])
		str[i] = keep[i];
	while (buff[j])
		str[i++] = buff[j++];
	str[ft_strlen(keep) + ft_strlen(buff)] = '\0';
	return (free(keep), str);
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
		(*keep) = ft_strjoin_modif((*keep), buff, -1, 0);
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
			return (free(keep), NULL);
		keep = ft_keep_memory(keep);
		if (!keep)
			return (free(line), NULL);
		return (line);
	}
	else
		return (NULL);
}
