/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:18:32 by alvina            #+#    #+#             */
/*   Updated: 2023/01/19 10:09:11 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	**free_tab(int **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int	tab_width(char *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (str[i])
	{
		if (str[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

static int	tab_length(char *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] != c && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			i++;			
	}
	return (nb);
}

static int	curr_length(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i])
	{
		if (str[i] == c || (str[i] >= '0' && str[i] <= '9'))
			break;
		i++;
	}
	return (i);
}

static int	**splitting(int **tab, char *s, char c)
{
	int	k;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = malloc(sizeof(int) * tab_length(&s[i], c));
			if (!tab)
				return (free_tab(tab, j));
			k = 0;
			while (s[i] != c && s[i])
			{
				tab[j][k] = ft_atoi(&s[i]);
				k++;
				i += curr_length(&s[i], c);
			}
			j++;
		}
		else
			i++;
	}
	return (tab);
}

int	**split_tab(char *s, char c)
{
	int		**tab;
	int     width;
	int		len;

	len = ft_strlen(s);
	s[len -1] = '\0';
	width = tab_width(s, c);
	tab = (int **) malloc(sizeof(int *) * width);
	if (!tab)
		return (NULL);
	tab = splitting(tab, s, c);
	return (tab);
}