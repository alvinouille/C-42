/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/26 18:54:54 by alvina           ###   ########.fr       */
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

void    tracing(t_data img, t_needle **tab, int width, int *length)
{
    int i = 0;
    int j = 0;

    while (j < width)
    {
        while (i < length[j] - 1)
        {
            bresenham(img, tab[j][i], tab[j][i + 1]);
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    while (i < length[j])
    {
        while (j < width - 1)
        {
            bresenham(img, tab[j][i], tab[j + 1][i]);
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

    i = 0;
    j = 0;
    t_needle **tab = malloc(sizeof (t_needle *) * width);
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

t_needle    **quadrillage(int **tab, t_vars *vars)
{
	int         x;
	int         y;
	t_point     curr;
	t_needle    **map;

	x = 0;
	y = 0;
	map = create(vars->leng, vars->width);
    if (!map)
            return (NULL);
	while (y < vars->width)
	{
		while (x < vars->leng[y])
		{
			curr.x = x;
			curr.y = y;
			curr.z = tab[y][x];
			map[y][x] = projection(curr, vars);
			x++;
		}
		x = 0;
		y++;
	}
	return (map);
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
            img_pixel_put(&(vars->img), i, j, 0x191970);
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
    t_needle    **map;
    int         i;

    i = 0;
    map = NULL;
    black_screen(vars);
    map = quadrillage(vars->tab, vars);
	if (!map)
        such_a_quitter(vars, 2);
    tracing(vars->img, map, vars->width, vars->leng);
    while (i < vars->width)
	{
		free(map[i]);
		i++;
	}
    free(map);
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

void	print(int **tab, int width, int *leng)
{
	int x = 0;
	int y = 0;
	while (y < width)
	{
		while (x < leng[y])
		{
			printf("%d ", tab[y][x]);
			x++;
		}
		printf("\n");
		x = 0;
		y++;
	}
}

int main(int ac, char **av)
{
    int     fd;
    char    *str;
    char    *tmp;
    t_vars  vars;

    str = NULL;
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
    vars.tab = split_tab(str, '\n', &vars);
    free(tmp);
	free(str);
    if (!vars.tab)
            such_a_quitter(&vars, 2);
	mlx(vars);
	return (0);
}
