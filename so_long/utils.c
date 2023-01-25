/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:31:09 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/25 13:51:15 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size > 0 && (nmemb > ((size_t)- 1 / size)))
		return (NULL);
	tab = (char *)malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (size * nmemb));
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
    if (s1)
	    length = ft_strlen(s1) + ft_strlen(s2);
    else
        length = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (s1)
    {
        while (s1[j])
		    str[i++] = s1[j++];
    }
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
    if (s1)
        free(s1);
    if (s2)
        free(s2);
	str[i] = '\0';
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
    write(fd, s, i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*(str++) = '\0';
		n--;
	}
}
