/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:54:40 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/01 21:05:18 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_ok(char **tab, char **tmp)
{
    if (!is_rectangular(tab))
        return (0);
    if (!wrong_char(tab))
        return (0);
    if (!cep_check(tab, 0, 0, 0))
        return (0);
    if (!is_closed(tab))
        return (0);
    if (!is_valid(tmp))
        return (0);
    return (1);
}

int is_closed(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    if (!check_col(tab) || !check_line(tab[0]) || !check_line(tab[i - 1]))
        return (0);
    return (1);
}

int wrong_char(char **tab)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (tab[i])
    {
        if (tab[i][j] == '\0')
            return (0);
        while (tab[i][j])
        {
            if (tab[i][j] != 'E' && tab[i][j] != 'C' && tab[i][j] != 'P'
                    && tab[i][j] != '0' && tab[i][j] != '1')
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}

int cep_check(char **tab, int e, int p, int c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (tab[i])
    {
        while (tab[i][j])
        {
            if (tab[i][j] == 'E')
                e++;
            if (tab[i][j] == 'P')
                p++;
            if (tab[i][j] == 'C')
                c++;
            j++;
        }
        j = 0;
        i++;
    }
    if (e != 1 || c < 1 || p != 1)
        return (0);
    return (1);
}

int is_rectangular(char **tab)
{
    int curr;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!tab)
        return (0);
    curr = ft_strlen(tab[0]);
    while (tab[i])
    {
        while (tab[i][j])
            j++;
        if (curr != j)
            return (0);
        j = 0;
        i++;
    }
    if (i <= 2)
        return (0);
    return (1);
}