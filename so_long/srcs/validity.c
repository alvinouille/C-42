/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:59:14 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/28 19:03:55 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_check(char **tab, char c1, char c2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[i])
    {
        while (tab[i][j])
        {
            if (tab[i][j] == c1 || tab[i][j] == c2)
                return (1);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

int     px_check(char **tab, int i)
{
    int j;

    j = 1;
    while (tab[i][j])
    {
        if (tab[i][j] == 'P' || tab[i][j] == 'X')
        {
            if (tab[i + 1][j] != '1' && tab[i + 1][j] != 'X')
                return (j);
            if (tab[i - 1][j] != '1' && tab[i - 1][j] != 'X')
                return (j);
            if (tab[i][j + 1] != '1' && tab[i][j + 1] != 'X')
                return (j);
            if (tab[i][j - 1] != '1' && tab[i][j - 1] != 'X')
                return (j);
        }
        j++;
    }
    return (-1);
}


void change_line(char *str, int pos, int *change)
{
    if (str[pos + 1] == '0' || str[pos + 1] == 'C')
    {
        str[pos + 1] = 'X';
        (*change) ++;
    }
    if (str[pos - 1] == '0' || str[pos - 1] == 'C')
    {
        str[pos - 1] = 'X';
        (*change) ++;
    }
    if (str[pos + 1] == 'E')
    {
        str[pos + 1] = '1';
        (*change) ++;
    }
    if (str[pos - 1] == 'E')
    {
        str[pos - 1] = '1';
        (*change) ++;
    }
}

void change_col(char **tab, int i, int pos, int *change)
{
    if (tab[i - 1][pos] == '0' || tab[i - 1][pos] == 'C')
    {
        tab[i - 1][pos] = 'X';
        (*change) ++;
    }
    if (tab[i + 1][pos] == '0' || tab[i + 1][pos] == 'C')
    {
        tab[i + 1][pos] = 'X';
        (*change) ++;
    }
    if (tab[i - 1][pos] == 'E')
    {
        tab[i - 1][pos] = '1';
        (*change) ++;
    }
    if (tab[i + 1][pos] == 'E')
    {
        tab[i + 1][pos] = '1';
        (*change) ++;
    }
}

int changing(char **tab)
{
    int i;
    int pos;
    int change;

    i = 1;
    pos = -1;
    change = 0;
    while (tab[i])
    {
        pos = px_check(tab, i);
        if (pos != -1)
        {
            change_line(tab[i], pos, &change);
            change_col(tab, i, pos, &change);
            tab[i][pos] = 'X';
            return (change);
        }
        i++;
    }
    return (0);
}

int is_valid(char **tab)
{
    int change;

    change = 1;
    while (change > 0)
    {
        change = 0;
        change = changing(tab);
    }
    if (char_check(tab, 'C', 'E'))
        return (0);
    return (1);
    
}