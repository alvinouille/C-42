/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:35:17 by alvina            #+#    #+#             */
/*   Updated: 2023/02/11 14:54:06 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first(t_data img, t_needle curr, t_needle next)
{
	int		dy;
	int		dx;
	float	e;
	int		x;
	int		y;

	x = curr.x;
	y = curr.y;
	e = next.x - curr.x;
	dx = 2 * e;
	dy = 2 * (next.y - curr.y);
	while (1)
	{
		if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
			img_pixel_put(&img, x, y, 0x00FFFFFF);
		if (x == next.x)
			break ;
		x++;
		e -= dy;
		if (e < 0)
		{
			y++;
			e += dx;
		}
	}
}

void	second(t_data img, t_needle curr, t_needle next)
{
	int		dy;
	int		dx;
	float	e;
	int		x;
	int		y;

	x = curr.x;
	y = curr.y;
	e = next.y - curr.y;
	dy = 2 * e;
	dx = 2 * (next.x - curr.x);
	while (1)
	{
		if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
			img_pixel_put(&img, x, y, 0x00FFFFFF);
		if (y == next.y)
			break ;
		y++;
		e -= dx;
		if (e < 0)
		{
			x++;
			e += dy;
		}
	}
}

void	vertical(t_data img, t_needle curr, t_needle next)
{
	int		x;
	int		y;

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

void	fifth(t_data img, t_needle curr, t_needle next)
{
	int		dy;
	int		dx;
	float	e;
	int		x;
	int		y;

	x = curr.x;
	y = curr.y;
	e = next.y - curr.y;
	dy = 2 * e;
	dx = 2 * (next.x - curr.x);
	while (1)
	{
		if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
			img_pixel_put(&img, x, y, 0x00FFFFFF);
		if (x == next.x)
			break ;
		x--;
		e -= dy;
		if (e >= 0)
		{
			y--;
			e += dx;
		}
	}
}

void	sixth(t_data img, t_needle curr, t_needle next)
{
	int		dy;
	int		dx;
	float	e;
	int		x;
	int		y;

	x = curr.x;
	y = curr.y;
	e = next.y - curr.y;
	dy = 2 * e;
	dx = 2 * (next.x - curr.x);
	while (1)
	{
		if (x < LENGTH && x > 0 && y < WIDTH && y > 0)
			img_pixel_put(&img, x, y, 0x00FFFFFF);
		if (y == next.y)
			break ;
		y--;
		e -= dx;
		if (e >= 0)
		{
			x--;
			e += dy;
		}
	}
}
