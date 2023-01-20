/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/20 20:00:18 by ale-sain         ###   ########.fr       */
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

t_needle		projection(t_point curr, int echelle, t_point origine, int width, int length)
{
	t_needle point;

	point.x = (curr.x - curr.y) * (sqrt(2.0) / 2);
	point.y = -(curr.z * (sqrt(2.0 / 3.0))) - (1 / (sqrt(6.0)) * -((curr.x + curr.y)));

	point.x = round((origine.x + point.x) * echelle);
	point.y = round((origine.y + point.y) * echelle);
	return (point);
}

void    bresenham(t_data img, t_needle curr, t_needle next)
{
    int dy = next.y - curr.y;
    int dx = next.x - curr.x;
    int x = curr.x;
    int y = curr.y;
    // printf("x = %d, y = %d\n", x, y);
    float e = 0.0;
    float pente;
    if (dx != 0)
        pente = (float)dy / (float)dx;
    else
        pente = 0;
    float ajust = - 1.0;
    printf("pente = %f\n", pente);
    if (pente >= 0)
    {
        //      AU DESSUS AXE ABSCISSE (X)
        //      OCTET 2 ET 1 (A DROITE AXE ORDONNE (Y))
        if (x < next.x)    
        {
            while (x <= next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e >= 0.5)
                {
                    y++;
                    e += ajust;
                }
                x++;
            }
        }
        //      SUR AXE ORDONNE
        else if (x == next.x)
        {
            if (y <= next.y)
            {
                while (y <= next.y)
                {
                    img_pixel_put(&img, x, y, 0x00FFFFFF);
                    y++;
                }
            }
            else
            {
                while (y >= next.y)
                {
                    img_pixel_put(&img, x, y, 0x00FFFFFF);
                    y--;
                }
            }
        }
        //      OCTANT 4 ET 3 (A GAUCHE AXE ORDONNE (Y))
        else
        {
            while (x >= next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e >= 0.5)
                {
                    y--;
                    e += ajust;
                }
                x--;
            }
        }
    }
    //  AU DESSOUS AXE ABSCISSE (X)
    else
    {
        //      OCTANT 8 ET 7 (A DROITE AXE ORDONNE (Y))
        if (x < next.x)
        {
            while (x <= next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e <= -0.5)
                {
                    y--;
                    e -= ajust;
                }
                x++;
            
            }
        }
        //      OCTANT 6 ET 5 (A GAUCHE AXE ORDONNE (Y))
        else
        {
            while (x >= next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e <= -0.5)
                {
                    y++;
                    e -= ajust;
                }
                x--;
                printf("x = %d, y = %d\n",x, y);
            }
        }
    }
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

t_needle    **quadrillage(t_data img, int **tab, int width, int length)
{
	int x;
	int y;
	t_point origine;
	t_point point;
	t_point curr;
	int echelle;
	t_needle **map;

	x = 0;
	y = 0;
	origine.x = 50;
	origine.y = 50;
	echelle = 15;
	int i = 0;
	map = create(length, width);
	while (y < width)
	{
		while (x < length)
		{
			curr.x = x;
			curr.y = y;
			curr.z = tab[y][x];
			// printf("z = %f", curr.z);
			map[y][x] = projection(curr, echelle, origine, length, width);
			// printf("%d eme point : x = %f, y = %f\n", i, point.x, point.y);
			img_pixel_put(&img, point.x, point.y, 0x00FFFFFF);
			x++;
			i++;
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
	exit(0);
}

void	display_point(int **tab, int width, int length)
{
	t_vars vars;
    t_data  img;
	t_needle **map;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF to come");
	
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    map = quadrillage(img, tab, width, length);
	tracing(img, map, width, length);
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
