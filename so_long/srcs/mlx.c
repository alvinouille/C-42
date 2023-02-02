/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:07:37 by alvina            #+#    #+#             */
/*   Updated: 2023/02/02 09:56:17 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	action_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		such_a_quitter(vars, 0);
	else if (keycode == XK_w)
		vars->moves += move_up(vars);
	else if (keycode == XK_a)
		vars->moves += move_left(vars);
	else if (keycode == XK_s)
		vars->moves += move_down(vars);
	else if (keycode == XK_d)
		vars->moves += move_right(vars);
	return (1);
}

int	closing_mouse(t_vars *vars)
{
	such_a_quitter(vars, 0);
	return (0);
}

void	mlx(char **tab)
{
	t_vars	vars;

	vars = initializing(tab);
	vars.moves = 1;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		such_a_quitter(&vars, 3);
	vars.win = mlx_new_window(vars.mlx, vars.length, vars.width, "Pacman game");
	if (!vars.win)
		such_a_quitter(&vars, 3);
	game_init(&vars);
	display_game(vars.tab, &vars);
	mlx_hook(vars.win, 2, 1L << 0, action_key, &vars);
	mlx_hook(vars.win, 17, 1L << 5, closing_mouse, &vars);
	mlx_loop(vars.mlx);
}

t_vars	initializing(char **tab)
{
	t_vars	vars;

	vars.img.player = NULL;
	vars.img.border = NULL;
	vars.img.background = NULL;
	vars.img.exit = NULL;
	vars.img.collec = NULL;
	vars.win = NULL;
	vars.mlx = NULL;
	vars.tab = tab;
	vars.width = width(tab) * 60;
	vars.length = ft_strlen(tab[0]) * 60;
	return (vars);
}

void	game_init(t_vars *vars)
{
	int	a;

	vars->img.player = mlx_xpm_file_to_image(vars->mlx, "img/p.xpm", &a, &a);
	if (!vars->img.player)
		such_a_quitter(vars, 3);
	vars->img.border = mlx_xpm_file_to_image(vars->mlx, "img/b.xpm", &a, &a);
	if (!vars->img.border)
		such_a_quitter(vars, 3);
	vars->img.background = mlx_xpm_file_to_image(vars->mlx,
			"img/bg.xpm", &a, &a);
	if (!vars->img.background)
		such_a_quitter(vars, 3);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx, "img/e.xpm", &a, &a);
	if (!vars->img.exit)
		such_a_quitter(vars, 3);
	vars->img.collec = mlx_xpm_file_to_image(vars->mlx, "img/c.xpm", &a, &a);
	if (!vars->img.collec)
		such_a_quitter(vars, 3);
}
