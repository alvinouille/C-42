/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brasenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:34:15 by alvina            #+#    #+#             */
/*   Updated: 2023/02/02 18:02:35 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	third(t_data img, t_needle curr, t_needle next)
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
		y++;
		if (y == next.y)
			break ;
		e += dx;
		if (e <= 0)
		{
			x--;
			e += dy;
		}
	}
}

void	fourth(t_data img, t_needle curr, t_needle next)
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
		x--;
		if (x == next.x)
			break ;
		e += dy;
		if (e >= 0)
		{
			y++;
			e += dx;
		}
	}
}

void	eight(t_data img, t_needle curr, t_needle next)
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
		x++;
		if (x == next.x)
			break ;
		e += dy;
		if (e < 0)
		{
			y--;
			e += dx;
		}
	}
}

void	seventh(t_data img, t_needle curr, t_needle next)
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
		y--;
		if (y == next.y)
			break ;
		e += dx;
		if (e > 0)
		{
			x++;
			e += dy;
		}
	}
}
