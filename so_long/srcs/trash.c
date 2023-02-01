/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:06:34 by alvina            #+#    #+#             */
/*   Updated: 2023/02/01 21:12:59 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    mlx_destroyer(t_vars *vars)
{
    if (vars->img.player)
        mlx_destroy_image(vars->mlx, vars->img.player);
    if (vars->img.border)
        mlx_destroy_image(vars->mlx, vars->img.border);
    if (vars->img.background)
        mlx_destroy_image(vars->mlx, vars->img.background);
    if (vars->img.exit)
        mlx_destroy_image(vars->mlx, vars->img.exit);
    if (vars->img.collec)
        mlx_destroy_image(vars->mlx, vars->img.collec);
    if (vars->win)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_window(vars->mlx, vars->win);
    }
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
}

void    such_a_quitter(t_vars *vars, int flag)
{
    int y;

	y = 0;
    if (vars->tab)
	{
        while (vars->tab[y])
	    {
		    free(vars->tab[y]);
		    y++;
	    }
	    free(vars->tab);
    }
    mlx_destroyer(vars);
    if (flag == 3)
            ft_putstr_fd("Mlx failed !\n", 2);
	exit(flag);
}

void    free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    clean_leaving_gnl(char *tmp, char *str, int fd)
{
    free(tmp);
    free(str);
    get_next_line(fd, 1);
    close(fd);
    ft_putstr_fd("Error\nInvalid map !\n", 2);
    exit(3);
}

void    free_machine(char **tab, char **tmp, char *str)
{
    if (str)
        free(str);
    if (!tmp)
    {
        if (tab)
            free_tab(tab);
        ft_putstr_fd("Error\nMalloc failed !\n", 2);
        exit(2);
    }
    free_tab(tmp);
    if (tab)
    {
        free_tab(tab);
        ft_putstr_fd("Error\nInvalid map !\n", 2);
        exit(3);
    }
}
