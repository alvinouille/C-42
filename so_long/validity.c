/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:59:14 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/25 15:16:06 by ale-sain         ###   ########.fr       */
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

int     px_check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == 'X' || str[i] == 'P')
            return (i);
        i++;
    }
    return (-1);
}

int changing(char **tab)
{
    int i;
    int pos;

    i = 0;
    pos = 0;
    while (tab[i])
    {
        pos = px_check(tab[i]);
        if (pos != -1)
        {
            if (tab[i][pos + 1] == '0' || tab[i][pos + 1] == 'C')
        }
    }
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
    if (char_check(tab, 'c', 'e'))
        return (0);
    return (1);
    
}