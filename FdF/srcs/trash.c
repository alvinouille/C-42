/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:28:29 by alvina            #+#    #+#             */
/*   Updated: 2023/02/01 20:37:23 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(int **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void    cleaning_tab(t_vars *vars)
{
    int i;

    i = 0;
    while (i < vars->width)
    {
        free(vars->tab[i]);
		i++;
    }
    free(vars->tab);
}

void    clean_mlx(t_vars *vars)
{
    if (vars->win && vars->mlx)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_window(vars->mlx, vars->win);
    }
    if (vars->img.img)
        mlx_destroy_image(vars->mlx, vars->img.img);
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
}

void    such_a_quitter(t_vars *vars, int flag)
{
    int     i;

    i = 0;
    if (flag != 2)
    {
        if (vars->tab)
        {
            while (i < vars->width)
            {
                free(vars->tab[i]);
                i++;
            }
            free(vars->tab);
        }
    }
    if (vars->leng)
        free(vars->leng);
    clean_mlx(vars);
    if (flag == 3)
        ft_putstr_fd("Mlx failed !\n", 2);
    if (flag == 2)
        ft_putstr_fd("Malloc failed !\n", 2);
    exit(flag);
}