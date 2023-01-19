/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/19 20:50:32 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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

int		around(float nb)
{
	if (nb - (int)nb > 0.5)
        return ((int)ceil(nb));
    else
		return ((int)floor(nb));
}

t_point		projection(t_point curr, int echelle, t_point origine, int width, int length)
{
	t_point point;
	
	// point.x = curr.x;
	// point.y = curr.y;
	point.x = round((double)(curr.x - curr.y) * (sqrt(2) / 2));
	point.y = round(((double)curr.z * (sqrt(2 / 3))) - ((double)1 / (sqrt(6)) * ((double)(curr.x + curr.y))));
	
	//	parallele la
	// point.x = round((double)(curr.x - curr.z) / (sqrt(2)));
	// point.y = round((double)(curr.x + (2 * curr.y) + curr.z) / sqrt(6));
	// point.x = (curr.x - curr.y) * cos(0.523599);
	// point.y = -curr.z + (curr.x + curr.y) * sin(0.523599);

	//another try
	// point.x = ((float)curr.x * 0.5 * (float)length) + ((float)curr.y * (-0.5) * (float)width);
	// point.y = ((float)curr.x * 0.25 * (float)length) + ((float)curr.y * 0.25 * (float)width);
	if (curr.y >= 1)
		point.x = (500 - (curr.y * echelle)) + (point.x * echelle);
	else
		point.x = 500 + (point.x * echelle);
	if (curr.y >= 1)
		point.y = (500 + (curr.y * echelle)) + (point.y * echelle);
	else
		point.y = 500 + (point.y * echelle);
	return (point);
}

void    quadrillage(t_data img, int **tab, int width, int length)
{
	int x;
	int y;
	t_point origine;
	t_point point;
	t_point curr;
	int echelle;

	x = 0;
	y = 0;
	origine.x = 500;
	origine.y = 500;
	echelle = 15;
	while (y < width)
	{
		while (x < length)
		{
			curr.x = x;
			curr.y = y;
			curr.z = tab[y][x];
			point = projection(curr, echelle, origine, length, width);
			img_pixel_put(&img, point.x, point.y, 0x00FF0000);
			x++;
		}
		x = 0;
		y++;
	}
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
	exit(0);
}

void	display_point(int **tab, int width, int length)
{
	t_vars vars;
    t_data  img;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF to come");
	
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    quadrillage(img, tab, width, length);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	vars.img = img;
	vars.tab = tab;
	vars.width = width;
    mlx_hook(vars.win, 2, 1L<<0, closing_key, &vars);
    mlx_hook(vars.win, 17, 1L<<5, closing_mouse, &vars);
    mlx_loop(vars.mlx);
}

int main(int ac, char **av)
{
    int     fd;
    char    *tmp;
    char    *str;
    int     **map;
	int		width;
	int		length;

	width = 0;
	length = 0;
    str = NULL;
    fd = open(av[1], O_RDONLY);
    if (fd == 0 || fd == -1)
        exit(1);
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
    map = split_tab(str, '\n');
	free(tmp);
	free(str);
	print(map, width, length);
	display_point(map, width, length);
	return (0);
}
