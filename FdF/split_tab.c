/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:18:32 by alvina            #+#    #+#             */
/*   Updated: 2023/01/24 15:40:32 by ale-sain         ###   ########.fr       */
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
	int flag;

	nb = 0;
	i = 0;
	flag = 0;
	while (str[i] != c && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
		{
			nb++;
			while (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
				i++;
			if (str[i] == ',')
			{
				i++;
				while (ft_isalnum(str[i]) == 1)
					i++;
			}
		}
		else
			i++;			
	}
	printf("length = %d\n", nb);
	return (nb);
}

static int	curr_length(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
		i++;
	if (str[i] == ',')
	{
		i++;
		while (ft_isalnum(str[i]) == 1)
			i++;
	}
	while (str[i])
	{
		if (str[i] == c || (str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			break;
		i++;
	}
	return (i);
}

static int	**splitting(int **tab, char *s, char c, t_vars *vars)
{
	int	k;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] >= '0' && s[i] <= '9')
		{
			tab[j] = malloc(sizeof(int) * tab_length(&s[i], c));
			vars->leng[j] = tab_length(&s[i], c);
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

int	**split_tab(char *s, char c, t_vars *vars)
{
	int		**tab;
	int     width;
	int		len;

	len = ft_strlen(s);
	s[len -1] = '\0';
	width = tab_width(s, c);
	tab = (int **) malloc(sizeof(int *) * width);
	vars->leng = (int *) malloc(sizeof(int) * width);
	if (!tab)
		return (NULL);
	tab = splitting(tab, s, c, vars);
	vars->width = width;
	return (tab);
}