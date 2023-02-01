/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:14:27 by alvina            #+#    #+#             */
/*   Updated: 2023/02/01 21:14:58 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    display_game(char **tab, t_vars *vars)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    
    while (tab[j])
    {
        while (tab[j][i])
        {
            display_img(tab[j][i], x, y, vars);
            x += 60;
            i++;
        }
        x = 0;
        i = 0;
        j++;
        y += 60;
    }
}

void    display_img(char c, int x, int y, t_vars *vars)
{
    if (c == '1')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.border, x, y);
    if (c == '0')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.background, x, y);
    if (c == 'E')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, x, y);
    if (c == 'P')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, x, y);
    if (c == 'C')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.collec, x, y);
}