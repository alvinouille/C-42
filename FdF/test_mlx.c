/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:09:00 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/17 14:46:46 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_data    img;
}				t_vars;

typedef struct s_args
{
    t_point start;
    t_point end;
    t_vars mlx;
}   t_args;


void	img_pixel_put(t_data *img, int x, int y, int color)
{
	char	*px;

	px = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)px = color;
}

void    square(t_data img, int x, int y)
{
    while (x++ < (1920 / 4) * 3)
        img_pixel_put(&img, x, y, 0x00FFFFFF);
    while (y++ < (1080 / 4) * 3)
        img_pixel_put(&img, x, y, 0x00FFFFFF);
    while (x-- > 1920 / 4)
        img_pixel_put(&img, x, y, 0x00FFFFFF);
    while (y-- > 1080 / 4)
        img_pixel_put(&img, x, y, 0x00FFFFFF);
}

void    triangle(t_data img, int x, int y)
{
    while (x++ < 1920 / 4 * 3 && y++ < (1080 / 4 * 3))
        img_pixel_put(&img, x, y, 0x00FFFFFF);
    while (x-- > 1920 / 4)
        img_pixel_put(&img, x, y, 0x00FFFF00);
    while (x++ < 1920 / 2 * 3 && y-- > (1080 / 4))
        img_pixel_put(&img, x, y, 0x00FFFFFF);
}

void    quadrillaged_losange(t_data img, int x, int y)
{
    while (x++ < 1920 / 4 * 3 && y++ < (1080 /2))
        img_pixel_put(&img, x, y, 0x00FFFFFF);
    while (x-- > 1920 / 2 && y++ < (1080 / 4 * 3))
        img_pixel_put(&img, x, y, 0x00FFFFFF);
    while (x-- > 1920 / 4 && y-- > 1080 / 2)
        img_pixel_put(&img, x, y, 0x00FFFF00);
    while (x++ < 1920 / 2 && y-- > (1080 / 4))
        img_pixel_put(&img, x, y, 0x00FFFFFF);
}

void    trace_line(t_data img, int x, int y, int echelle)
{
    int i;
    
    i = x;
    while (i++ <= (x + echelle))
        img_pixel_put(&img, i, y, 0x00FFFFFF);
}

void    trace_col(t_data img, int x, int y, int echelle)
{
    int i;

    i = y;
    while (i++ <= y + echelle)
        img_pixel_put(&img, x, i, 0x00FFFFFF);
}

void    quadrillage(t_data img, t_point pos, t_point end, int echelle)
{
    int x;
    int y;

    x = pos.x;
    y = pos.y;
    while (y <= end.y)
    {
        while (x <= end.x)
        {
            if (x != end.x)
                trace_line(img, x, y, echelle);
            if (y != end.y)
                trace_col(img, x, y, echelle);
            x += echelle;
        }
        x = pos.x;
        y += echelle;
    }
}

// int	key_hook(int keycode, t_args *arg)
// {
//     printf("here : %d\n", keycode);
//     if (keycode == 119) //W
//         arg->start.y -= 50;
//     else if (keycode == 97) //A
//         arg->start.x -= 50;
//     else if (keycode == 115) //S
//         arg->start.y += 50;
//     else if (keycode == 200) //D
//         arg->start.x += 50;
//     else
//         return (0);
//     quadrillage(arg->mlx.img, arg->start, arg->end, 100);
//     mlx_put_image_to_window(arg->mlx.mlx, arg->mlx.win, arg->mlx.img.img, 0, 0);
// }

int closing_key(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_image(vars->mlx, vars->img.img);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        exit(0);
    }
    return (0);
}

int closing_mouse(t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_image(vars->mlx, vars->img.img);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit(0);
}

void    initialising(t_point *name, int x, int y)
{
    name->x = x;
    name->y = y;
}

int main()
{
    t_vars vars;
    t_data  img;
    int length;
    int width;
    t_point start;
    t_point end;
    t_args arg;

    length = 1920;
    width = 1080;
    initialising(&start, length/2, width/2);
    initialising(&end, start.x + 400, start.y + 300);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, length, width, "FdF to come");
    img.img = mlx_new_image(vars.mlx, length, width);
    vars.img = img;
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    arg.start = start;
    arg.end = end;
    arg.mlx = vars;
    // square(img, length/4, length/4);
    // triangle(img, length/2, width/4);
    // quadrillaged_losange(img, length/2, width/4);
    quadrillage(img, start, end, 100);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    
    mlx_hook(vars.win, 2, 1L<<0, closing_key, &vars);
    mlx_hook(vars.win, 17, 1L<<5, closing_mouse, &vars);
    // mlx_key_hook(vars.win, key_hook, &arg);
    mlx_loop(vars.mlx); //ouvre fenetre + gere evenements (aku mado chu ni user ga sosa o suru)
}