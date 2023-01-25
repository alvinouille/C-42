/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:24 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/25 21:04:07 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int    c_left(t_vars *vars)
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

void    move_up(t_vars *vars)
{
    int i;
    int j;
    int flag;

    flag = 0;
    i = 0;
    j = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i - 1][j] != '1')
                {
                    if (vars->tab[i - 1][j] == 'E' && c_left(vars) == 0)
                    {
                        vars->tab[i - 1][j] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                        exit(0);
                    }
                    else if (vars->tab[i - 1][j] != 'E')
                    {
                        vars->tab[i - 1][j] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                    }
                }
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
    int flag;

    i = 0;
    j = 0;
    flag = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i + 1][j] != '1')
                {
                    if (vars->tab[i + 1][j] == 'E' && c_left(vars) == 0)
                    {
                        vars->tab[i + 1][j] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                        exit(0);
                    }
                    else if (vars->tab[i + 1][j] != 'E')
                    {
                        vars->tab[i + 1][j] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                    }
                }
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
    int flag;

    i = 0;
    flag = 0;
    j = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i][j - 1] != '1')
                {
                    if (vars->tab[i][j - 1] == 'E' && c_left(vars) == 0)
                    {
                        vars->tab[i][j - 1] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                        exit(0);
                    }
                    else if (vars->tab[i][j - 1] != 'E')
                    {
                        vars->tab[i][j - 1] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                    }
                }
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
    int flag;

    i = 0;
    j = 0;
    flag = 0;
    while (vars->tab[i])
    {
        while (vars->tab[i][j])
        {
            if (vars->tab[i][j] == 'P')
            {
                if (vars->tab[i][j + 1] != '1')
                {
                   if (vars->tab[i][j + 1] == 'E' && c_left(vars) == 0)
                    {
                        vars->tab[i][j + 1] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                        exit(0);
                    }
                    else if (vars->tab[i][j + 1] != 'E')
                    {
                        vars->tab[i][j + 1] = 'P';
                        vars->tab[i][j] = '0';
                        display_game(vars->tab, vars);
                    }
                }
                return ;
            }
            j++;
        }
        j = 0;
        i++;
    }
}