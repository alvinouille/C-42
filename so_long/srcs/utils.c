/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:31:09 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/01 21:11:44 by alvina           ###   ########.fr       */
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
	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (NULL);
	}
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j]
			&& (i + j) < len && big[i + j])
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

int check_col(char **tab)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(tab[0]);
    while (tab[i])
    {
        if (tab[i][0] != '1' || tab[i][len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int     width(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}
