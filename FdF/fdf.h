/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:15:33 by alvina            #+#    #+#             */
/*   Updated: 2023/01/25 10:47:58 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "get_next_line/get_next_line.h"
#include <math.h>

typedef struct s_needle
{
    double x;
    double y;
}   t_needle;

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
    double x;
    double y;
    double z;
}   t_point;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_data  img;
    int     **tab;
    int     width;
    int     echelle;
    t_point origine;
    t_needle **map;
    int     *leng;
}				t_vars;


//      UTILS
char	*ft_strjoin(char *s1, char *s2);
int     ft_atoi(char *nptr);
int     ft_strlen_modif(char *str);
void	ft_putstr_fd(char *s, int fd);
int		around(float nb);
int	ft_isalnum(int c);
void	print(int **tab, int width, int *leng);

//      MLX
void	img_pixel_put(t_data *img, int x, int y, int color);

//		BRASENHAM
void    first(t_data img, t_needle curr, t_needle next);
void    second(t_data img, t_needle curr, t_needle next);
void    vertical(t_data img, t_needle curr, t_needle next);
void    fifth(t_data img, t_needle curr, t_needle next);
void    sixth(t_data img, t_needle curr, t_needle next);
void    third(t_data img, t_needle curr, t_needle next);
void    fourth(t_data img, t_needle curr, t_needle next);
void    eight(t_data img, t_needle curr, t_needle next);
void    seventh(t_data img, t_needle curr, t_needle next);
void    bresenham(t_data img, t_needle curr, t_needle next);

//      PARSING
int	**split_tab(char *s, char c, t_vars *vars);

#endif