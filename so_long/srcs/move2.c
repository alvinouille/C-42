/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:04:18 by alvina            #+#    #+#             */
/*   Updated: 2023/02/02 09:54:55 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->tab[i])
	{
		while (vars->tab[i][j])
		{
			if (vars->tab[i][j] == 'P')
			{
				if (vars->tab[i - 1][j] != '1')
					return (up_and_down(vars, i - 1, i, j));
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	move_down(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->tab[i])
	{
		while (vars->tab[i][j])
		{
			if (vars->tab[i][j] == 'P')
			{
				if (vars->tab[i + 1][j] != '1')
					return (up_and_down(vars, i + 1, i, j));
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	move_left(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->tab[i])
	{
		while (vars->tab[i][j])
		{
			if (vars->tab[i][j] == 'P')
			{
				if (vars->tab[i][j - 1] != '1')
					return (left_and_right(vars, i, j - 1, j));
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	move_right(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->tab[i])
	{
		while (vars->tab[i][j])
		{
			if (vars->tab[i][j] == 'P')
			{
				if (vars->tab[i][j + 1] != '1')
					return (left_and_right(vars, i, j + 1, j));
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
