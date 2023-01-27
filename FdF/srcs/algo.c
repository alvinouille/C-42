/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/27 12:13:05 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define LENGTH 1920
# define WIDTH 1080

int		around(float nb)
{
	if (nb - (int)nb > 0.5)
        return ((int)ceil(nb));
    else
		return ((int)floor(nb));
}

t_needle		projection(t_point curr, t_vars *vars)
{
	t_needle point;

	point.x = (curr.x - curr.y) * (sqrt(2.0) / 2);
	point.y = -(curr.z * (sqrt(2.0 / 3.0))) - (1 / (sqrt(6.0)) * -((curr.x + curr.y)));

	point.x = round((vars->origine.x + point.x) * vars->echelle);
	point.y = round((vars->origine.y + point.y) * vars->echelle);

	return (point);
}

void    tracing(t_vars vars)
{
    int i = 0;
    int j = 0;

    while (j < vars.width)
    {
        while (i < vars.leng[j] - 1)
        {
            bresenham(vars.img, vars.map[j][i], vars.map[j][i + 1]);
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    while (i < vars.leng[j])
    {
        while (j < vars.width - 1)
        {
            bresenham(vars.img, vars.map[j][i], vars.map[j + 1][i]);
            j++;
        }
        j = 0;
        i++;
    }

}

t_needle **create(int *length, int width)
{
    int i;
    int j;
    t_needle **tab;

    i = 0;
    j = 0;
    tab = malloc(sizeof (t_needle *) * width);
    if (!tab)
        return (NULL);
    while (i < width)
    {
        tab[i] = malloc(sizeof(t_needle) * length[i]);
        if (!tab[i])
        {
            while (j < i)
	        {
		        free(tab[j]);
		        j++;
	        }
            free(tab);
            return (NULL);
        }
        i++;
    }
    return (tab);
}

void    quadrillage(t_vars *vars)
{
	int         x;
	int         y;
	t_point     curr;

	x = 0;
	y = 0;
	vars->map = create(vars->leng, vars->width);
    if (!vars->map)
            return ;
	while (y < vars->width)
	{
		while (x < vars->leng[y])
		{
			curr.x = x;
			curr.y = y;
			curr.z = vars->tab[y][x];
			vars->map[y][x] = projection(curr, vars);
			x++;
		}
		x = 0;
		y++;
	}
}

void    black_screen(t_vars *vars)
{
    double i;
    double j;

    i = 1;
    j = 1;
    while (j < WIDTH)
    {
        while (i < LENGTH)
        {
            img_pixel_put(&(vars->img), i, j, 0x00000000);
            i++;
        }
        i = 0;
        j++;
    }
}

int closing_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
        such_a_quitter(vars, 0);
    return (0);
}

int closing_mouse(t_vars *vars)
{
    such_a_quitter(vars, 0);
    return (0);
}

int    fdf(t_vars *vars)
{
    int         i;

    i = 0;
    black_screen(vars);
    quadrillage(vars);
	if (!vars->map)
        such_a_quitter(vars, 2);
    tracing(*vars);
    while (i < vars->width)
	{
		free(vars->map[i]);
		i++;
	}
    free(vars->map);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
    return (0);
}

int     key_hook(int keycode, t_vars *vars)
{
    if (keycode == XK_w)
        vars->origine.y -=1;
    if (keycode == XK_a)
        vars->origine.x -=1;
    if (keycode == XK_s)
        vars->origine.y +=1;
    if (keycode == XK_d)
        vars->origine.x +=1;
    if (keycode == XK_o)
        vars->echelle += 1;
    if (keycode == XK_u)
        vars->echelle -= 1;
    return (0);
}

void    clean_mlx(t_vars *vars)
{
    if (vars->win)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_window(vars->mlx, vars->win);
    }
    if (vars->img.img)
        mlx_destroy_image(vars->mlx, vars->img.img);
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
}

void    such_a_quitter(t_vars *vars, int flag)
{
    int     i;

    i = 0;
    while (i < vars->width)
	{
		free(vars->tab[i]);
		i++;
	}
	free(vars->tab);
    free(vars->leng);
    clean_mlx(vars);
    if (flag == 3)
        ft_putstr_fd("Mlx failed !\n", 2);
    if (flag == 2)
        ft_putstr_fd("Malloc failed !\n", 2);
    exit(flag);
}

void	mlx(t_vars vars)
{
    vars.win = NULL;
    vars.img.img = NULL;
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
    vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img.bits_per_pixel), &(vars.img.line_length), &(vars.img.endian));
    if (!vars.img.addr)
        such_a_quitter(&vars, 3);
    mlx_loop_hook(vars.mlx, fdf, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, closing_key, &vars);
    mlx_hook(vars.win, 17, 1L<<5, closing_mouse, &vars);
    mlx_loop(vars.mlx);
}

int     arg_check(int ac, char **av)
{
    int fd;

    if (ac == 1 || ac > 2)
    {
        ft_putstr_fd("  usage: ./fdf <map>\n", 2);
        exit(1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == 0 || fd == -1)
    {
        ft_putstr_fd(av[1], 2);
        perror(" ");
        exit(1);
    }
    return (fd);
}

char    *gnl(int fd)
{
    char    *str;
    char    *tmp;

    str = NULL;
    while (1)
    {
        tmp = get_next_line(fd, 0);
        if (!tmp)
            break;
        str = ft_strjoin(str, tmp);
        if (!str)
        {
            free(tmp);
            ft_putstr_fd("Malloc failed !\n", 2);
            exit(2);
        }
    }
    if (!tmp && !str)
        exit(1);
    free(tmp);
    return (str);
}

int main(int ac, char **av)
{
    int     fd;
    char    *str;
    t_vars  vars;

    fd = arg_check(ac, av);
    str = gnl(fd);
    vars.tab = split_tab(str, '\n', &vars);
	if (str)
        free(str);
    if (!vars.tab)
            such_a_quitter(&vars, 2);
	mlx(vars);
	return (0);
}
