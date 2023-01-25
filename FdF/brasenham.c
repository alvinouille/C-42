/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:47:29 by alvina            #+#    #+#             */
/*   Updated: 2023/01/25 09:26:20 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define LENGTH 1920
# define WIDTH 1080

void    first(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.x - curr.x;
    dx = 2 * e;
    dy = 2 * (next.y - curr.y);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        x++;
        if (x == next.x)
            break;
        e -= dy;
        if (e < 0)
        {
            y++;
            e += dx;
        }
    }
}

void    second(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.y - curr.y;
    dy = 2 * e;
    dx = 2 * (next.x - curr.x);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        y++;
        if (y == next.y)
            break;
        e -= dx;
        if (e < 0)
        {
            x++;
            e +=  dy;
        }
    }
}

void    vertical(t_data img, t_needle curr, t_needle next)
{
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    if (y <= next.y)
    {
        while (y <= next.y)
        {
            if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
                img_pixel_put(&img, x, y, 0x00FFFFFF);
            y++;
        }
    }
    else
    {
        while (y >= next.y)
        {
            if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
                img_pixel_put(&img, x, y, 0x00FFFFFF);
            y--;
        }
    }
}

void    fifth(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.y - curr.y;
    dy = 2 * e;
    dx = 2 * (next.x - curr.x);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        x--;
        if (x == next.x)
            break;
        e -= dy;
        if (e >= 0)
        {
            y--;
            e += dx;
        }
    }
}

void    sixth(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.y - curr.y;
    dy = 2 * e;
    dx = 2 * (next.x - curr.x);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        y--;
        if (y == next.y)
            break;
        e -= dx;
        if (e >= 0)
        {
            x--;
            e += dy;
        }
    }
}

void    third(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.y - curr.y;
    dy = 2 * e;
    dx = 2 * (next.x - curr.x);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        y++;
        if (y == next.y)
            break;
        e += dx;
        if (e <= 0)
        {
            x--;
            e += dy;
        }
    }
}

void    fourth(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.x - curr.x;
    dx = 2 * e;
    dy = 2 * (next.y - curr.y);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        x--;
        if (x == next.x)
            break;
        e += dy;
        if (e >= 0)
        {
            y++;
            e += dx;
        }
    }
}

void    eight(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.x - curr.x;
    dx = 2 * e;
    dy = 2 * (next.y - curr.y);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        x++;
        if (x == next.x)
            break;
        e += dy;
        if (e < 0)
        {
            y--;
            e += dx;
        }
    }
}

void    seventh(t_data img, t_needle curr, t_needle next)
{
    int dy;
    int dx;
    float e;
    int x;
    int y;
    x = curr.x;
    y = curr.y;
    e = next.y - curr.y;
    dy = 2 * e;
    dx = 2 * (next.x - curr.x);
    while (1)
    {
        if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
            img_pixel_put(&img, x, y, 0x00FFFFFF);
        y--;
        if (y == next.y)
            break;
        e += dx;
        if (e > 0)
        {
            x++;
            e += dy;
        }
    }
}

void    bresenham(t_data img, t_needle curr, t_needle next)
{
    int dy = next.y - curr.y;
    int dx = next.x - curr.x;
    int x = curr.x;
    int y = curr.y;
    float e = 0.0;
    float pente;
    if (dx != 0)
        pente = (float)dy / (float)dx;
    else
    {
        pente = (float)dy;
        if (dy < 0)
            pente = -pente;
    }
    if (pente >= 0)
    {
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
    else
    {
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
}