/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:47:29 by alvina            #+#    #+#             */
/*   Updated: 2023/02/01 20:35:41 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define LENGTH 1920
# define WIDTH 1080

static void    going_up(t_data img, t_needle curr, t_needle next, float pente)
{
    int x;

    x = curr.x;
    if (x < next.x)    
    {
        if (pente >= 1)
            second(img, curr, next);
        else
            first(img, curr, next);
    }
    else if (x == next.x)
        vertical(img, curr, next);
    else
    {
        if (pente < 1)
            fifth(img, curr, next);
        else
            sixth(img, curr, next);
    }
}

static void    going_down(t_data img, t_needle curr, t_needle next, float pente)
{
    int     x;

    x = curr.x;
    if (x < next.x)
    {
        if (pente >= -1)
            eight(img, curr, next);
        else
            seventh(img, curr, next);
    }
    else
    {
        if (pente < -1)
            third(img, curr, next);
        else
            fourth(img, curr, next);
    }
}

void    bresenham(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float pente;

    dy = next.y - curr.y;
    dx = next.x - curr.x;
    if (dx != 0)
        pente = (float)dy / (float)dx;
    else
    {
        pente = (float)dy;
        if (dy < 0)
            pente = -pente;
    }
    if (pente >= 0)
        going_up(img, curr, next, pente);
    else
        going_down(img, curr, next, pente);
}