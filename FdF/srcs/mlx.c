/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:52:24 by alvina            #+#    #+#             */
/*   Updated: 2023/02/03 16:44:42 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx(t_vars vars)
{
	vars.echelle = 25;
	vars.origine.x = LENGTH / vars.echelle / 2;
	vars.origine.y = WIDTH / vars.echelle / 2;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		such_a_quitter(&vars, 3);
	vars.win = mlx_new_window(vars.mlx, LENGTH, WIDTH, "FdF to come");
	if (!vars.win)
		such_a_quitter(&vars, 3);
	vars.img.img = mlx_new_image(vars.mlx, LENGTH, WIDTH);
	if (!vars.img.img)
		such_a_quitter(&vars, 3);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img.bits_per_pixel),
			&(vars.img.line_length), &(vars.img.endian));
	if (!vars.img.addr)
		such_a_quitter(&vars, 3);
	mlx_loop_hook(vars.mlx, fdf, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, closing_key, &vars);
	mlx_hook(vars.win, 17, 1L << 5, closing_mouse, &vars);
	mlx_loop(vars.mlx);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_w)
		vars->origine.y -= 1;
	if (keycode == XK_a)
		vars->origine.x -= 1;
	if (keycode == XK_s)
		vars->origine.y += 1;
	if (keycode == XK_d)
		vars->origine.x += 1;
	if (keycode == XK_o)
		vars->echelle += 1;
	if (keycode == XK_u)
		vars->echelle -= 1;
	return (0);
}

int	closing_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		such_a_quitter(vars, 0);
	return (0);
}

int	closing_mouse(t_vars *vars)
{
	such_a_quitter(vars, 0);
	return (0);
}

int	fdf(t_vars *vars)
{
	int	i;

	i = 0;
	black_screen(vars);
	quadrillage(vars);
	if (!vars->map)
		such_a_quitter(vars, 2);
	if (vars->width == 1 && vars->leng[0] == 1)
	{
		img_pixel_put(&(vars->img), vars->map[0][0].x,
			vars->map[0][0].y, 0x00FFFFFF);
	}
	else
		tracing(*vars, 0, 0);
	while (i < vars->width)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
