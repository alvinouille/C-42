/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:18:32 by alvina            #+#    #+#             */
/*   Updated: 2023/02/03 17:44:35 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	tab_length(char *str, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] != c && str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			nb++;
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
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
	return (nb);
}

int	curr_length(char *str, char c)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
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
			break ;
		i++;
	}
	return (i);
}

int	splitting(char *s, char c, t_vars *vars)
{
	int	k;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
		{
			vars->tab[vars->width] = malloc(sizeof(int) * tab_length(&s[i], c));
			if (!vars->tab[vars->width])
				return (free_tab(vars->tab, vars->width), 0);
			vars->leng[vars->width] = tab_length(&s[i], c);
			k = 0;
			while (s[i] != c && s[i])
			{
				vars->tab[vars->width][k] = ft_atoi(&s[i]);
				k++;
				i += curr_length(&s[i], c);
			}
			vars->width++;
		}
		else
			i++;
	}
	return (1);
}

int	split_tab(char *s, char c, t_vars *vars)
{
	int	width;

	if (!s)
		return (0);
	width = tab_width(s, c);
	vars->tab = (int **) malloc(sizeof(int *) * width);
	vars->leng = (int *) malloc(sizeof(int) * width);
	if (!vars->tab)
		return (0);
	vars->width = 0;
	if (!vars->leng)
	{
		cleaning_tab(vars);
		return (0);
	}
	if (!splitting(s, c, vars))
		return (2);
	return (1);
}
