/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:30:29 by alvina            #+#    #+#             */
/*   Updated: 2023/02/02 18:02:50 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tracing(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (vars.width == 1 && vars.leng[0] == 1)
	{
		img_pixel_put(&(vars.img), vars.map[0][0].x,
			vars.map[0][0].y, 0x00FFFFFF);
		return ;
	}
	while (j < vars.width)
	{
		while (i < vars.leng[j] - 1)
		{
			bresenham(vars.img, vars.map[j][i], vars.map[j][i + 1]);
			i++;
		}
		i = 0;
		j++;
	}
	i = 0;
	j = 0;
	while (i < vars.leng[j])
	{
		while (j < vars.width - 1)
		{
			bresenham(vars.img, vars.map[j][i], vars.map[j + 1][i]);
			j++;
		}
		j = 0;
		i++;
	}
}

t_needle	**create(int *length, int width, t_vars *vars)
{
	int			i;
	int			j;
	t_needle	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof (t_needle *) * width);
	if (!tab)
	{
		cleaning_tab(vars);
		return (NULL);
	}
	while (i < width)
	{
		tab[i] = malloc(sizeof(t_needle) * length[i]);
		if (!tab[i])
		{
			while (j < i)
			{
				free(tab[j]);
				j++;
			}
			free(tab);
			cleaning_tab(vars);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

void	quadrillage(t_vars *vars)
{
	int			x;
	int			y;
	t_point		curr;

	x = 0;
	y = 0;
	vars->map = create(vars->leng, vars->width, vars);
	if (!vars->map)
		return ;
	while (y < vars->width)
	{
		while (x < vars->leng[y])
		{
			curr.x = x;
			curr.y = y;
			curr.z = vars->tab[y][x];
			vars->map[y][x] = projection(curr, vars);
			x++;
		}
		x = 0;
		y++;
	}
}

void	black_screen(t_vars *vars)
{
	double	i;
	double	j;

	i = 1;
	j = 1;
	while (j < WIDTH)
	{
		while (i < LENGTH)
		{
			img_pixel_put(&(vars->img), i, j, 0x00000000);
			i++;
		}
		i = 0;
		j++;
	}
}
