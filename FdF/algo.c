/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/23 20:20:30 by alvina           ###   ########.fr       */
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

t_needle		projection(t_point curr, int echelle, t_point origine)
{
	t_needle point;

	point.x = (curr.x - curr.y) * (sqrt(2.0) / 2);
	point.y = -(curr.z * (sqrt(2.0 / 3.0))) - (1 / (sqrt(6.0)) * -((curr.x + curr.y)));

	point.x = round((origine.x + point.x) * echelle);
	point.y = round((origine.y + point.y) * echelle);
	return (point);
}

void    tracing(t_data img, t_needle **tab, int width, int length)
{
    int i = 0;
    int j = 0;

    while (j < width)
    {
        while (i < length -1)
        {
            bresenham(img, tab[j][i], tab[j][i + 1]);
            // img_pixel_put(&img, tab[j][i].x, tab[j][i].y, 0x00FFFFFF);
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    while (i < length)
    {
        while (j < width -1)
        {
            bresenham(img, tab[j][i], tab[j + 1][i]);
            // img_pixel_put(&img, tab[j][i].x, tab[j][i].y, 0x00FFFFFF);
            j++;
        }
        j = 0;
        i++;
    }

}

t_needle **create(int length, int width)
{
    int i;

    i = 0;
    t_needle **tab = malloc(sizeof (t_needle *) * width);
    while (i < width)
    {
        tab[i] = malloc(sizeof(t_needle) * length);
        i++;
    }
    return (tab);
}

t_needle    **quadrillage(int **tab, int width, int length, t_vars *vars)
{
	int         x;
	int         y;
	t_point     curr;
	t_needle    **map;

	x = 0;
	y = 0;
	vars->origine.x = LENGTH / vars->echelle / 2;
	vars->origine.y = WIDTH / vars->echelle / 2;
	map = create(length, width);
	while (y < width)
	{
		while (x < length)
		{
			curr.x = x;
			curr.y = y;
			curr.z = tab[y][x];
			map[y][x] = projection(curr, vars->echelle, vars->origine);
			x++;
		}
		x = 0;
		y++;
	}
	return (map);
}

int closing_key(int keycode, t_vars *vars)
{
    int y;

	y = 0;
	if (keycode == 65307)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_image(vars->mlx, vars->img.img);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
		while (y < vars->width)
		{
			free(vars->tab[y]);
			y++;
		}
		free(vars->tab);
		exit(0);
    }
    return (0);
}

int closing_mouse(t_vars *vars)
{
    int y;

	y = 0;
	mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_image(vars->mlx, vars->img.img);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
	while (y < vars->width)
	{
		free(vars->tab[y]);
		y++;
	}
	free(vars->tab);
    y = 0;
    while (y < vars->width)
	{
		free(vars->map[y]);
		y++;
	}
    free(vars->map);
	exit(0);
}

void    fdf(int **tab, int width, int length, t_vars *vars)
{
    t_needle **map;

    vars->echelle = 10;
    vars->tab = tab;
    vars->width = width;
    map = quadrillage(tab, width, length, vars);
	tracing(vars->img, map, width, length);
    vars->map = map;
}

void	mlx(int **tab, int width, int length)
{
	t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, LENGTH, WIDTH, "FdF to come");
	vars.img.img = mlx_new_image(vars.mlx, LENGTH, WIDTH);
    vars.img.addr = mlx_get_data_addr(vars.img.img, &(vars.img.bits_per_pixel), &(vars.img.line_length), &(vars.img.endian));
    fdf(tab, width, length, &vars);
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    // mlx_expose_hook(vars.win, mouse_hook, &vars);
    // mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, closing_key, &vars);
    mlx_hook(vars.win, 17, 1L<<5, closing_mouse, &vars);
    mlx_loop(vars.mlx);
}

void	print(int **tab, int width, int length)
{
	printf("\n\n\n");
	int x = 0;
	int y = 0;
	while (y < width)
	{
		while (x < length)
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
	int		width;
	int		length;
    int     **tab;
    char    *str;
    char *tmp;

	width = 0;
	length = 0;
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
		printf("%s", tmp);
		length = ft_strlen_modif(tmp);
        str = ft_strjoin(str, tmp);
        if (!str)
            exit(1);
		width++;
    }
    tab = split_tab(str, '\n');
	free(tmp);
	free(str);
	// print(tab, width, length);
	mlx(tab, width, length);
	return (0);
}
