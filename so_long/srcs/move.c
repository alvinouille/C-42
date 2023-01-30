/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:24 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/28 19:08:19 by alvina           ###   ########.fr       */
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

void    up_and_down(t_vars *vars, int x, int x2, int y)
{
    if (vars->tab[x][y] == 'E' && c_left(vars) == 0)
    {
        vars->tab[x][y] = 'P';
        vars->tab[x2][y] = '0';
        display_game(vars->tab, vars);
        such_a_quitter(vars, 0);
    }
    else if (vars->tab[x][y] != 'E')
    {
        vars->tab[x][y] = 'P';
        vars->tab[x2][y] = '0';
        display_game(vars->tab, vars);
    }
}

void    left_and_right(t_vars *vars, int x, int y, int y2)
{
    if (vars->tab[x][y] == 'E' && c_left(vars) == 0)
    {
        vars->tab[x][y] = 'P';
        vars->tab[x][y2] = '0';
        display_game(vars->tab, vars);
        such_a_quitter(vars, 0);
    }
    else if (vars->tab[x][y] != 'E')
    {
        vars->tab[x][y] = 'P';
        vars->tab[x][y2] = '0';
        display_game(vars->tab, vars);
    }
}

void    move_up(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i - 1][j] != '1')
                    up_and_down(vars, i - 1, i, j);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    move_down(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i + 1][j] != '1')
                    up_and_down(vars, i + 1, i, j);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    move_left(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i][j - 1] != '1')
                    left_and_right(vars, i, j - 1, j);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

void    move_right(t_vars *vars)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i][j + 1] != '1')
                    left_and_right(vars, i, j + 1, j);
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}