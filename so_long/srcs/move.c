/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:24 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/01 21:04:35 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    c_left(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->tab[j])
    {
        while (vars->tab[j][i])
        {
            if (vars->tab[j][i] == 'C')
                return (1);
            i++;
        }
        i = 0;
        j ++;
    }
    return (0);
}

int    up_and_down(t_vars *vars, int x, int x2, int y, int a)
{
    if (vars->tab[x][y] == 'E' && c_left(vars) == 0)
    {
        vars->tab[x][y] = 'P';
        vars->tab[x2][y] = '0';
        display_game(vars->tab, vars);
        printf("moves : %d\n", a);
        such_a_quitter(vars, 0);
    }
    else if (vars->tab[x][y] != 'E')
    {
        vars->tab[x][y] = 'P';
        vars->tab[x2][y] = '0';
        display_game(vars->tab, vars);
        printf("moves : %d\n", a);
        return (1);
    }
    return (0);
}

int    left_and_right(t_vars *vars, int x, int y, int y2, int a)
{
    if (vars->tab[x][y] == 'E' && c_left(vars) == 0)
    {
        vars->tab[x][y] = 'P';
        vars->tab[x][y2] = '0';
        display_game(vars->tab, vars);
        printf("moves : %d\n", a);
        such_a_quitter(vars, 0);
    }
    else if (vars->tab[x][y] != 'E')
    {
        vars->tab[x][y] = 'P';
        vars->tab[x][y2] = '0';
        display_game(vars->tab, vars);
        printf("moves : %d\n", a);
        return (1);
    }
    return (0);
}