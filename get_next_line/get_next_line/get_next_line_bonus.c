/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:45:58 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/23 08:08:45 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_modif(char *keep, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!keep)
	{
		keep = (char *)malloc(1 * sizeof(char));
		keep[0] = '\0';
	}
	if (!buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(keep) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
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
		return (NULL);
	size = 1;
	while (!(ft_strchr((*keep), '\n')) && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == (size_t) - 1)
		{
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
	static char	*keep[1024];
	
	if (flag == 1)
	{
		free(keep);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (loopin(fd, &keep[fd]))
	{
		line = ft_line(keep[fd]);
		keep[fd] = ft_keep_memory(keep[fd]);
		return (line);
	}
	else
		return (NULL);
}
