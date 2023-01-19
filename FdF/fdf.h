/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:15:33 by alvina            #+#    #+#             */
/*   Updated: 2023/01/19 17:49:13 by alvina           ###   ########.fr       */
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

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_data  img;
    int     **tab;
    int     width;
}				t_vars;

typedef struct s_point
{
    int x;
    int y;
    int z;
}   t_point;

//      UTILS
char	*ft_strjoin(char *s1, char *s2);
int     ft_atoi(char *nptr);
int     **split_tab(char *s, char c);
int     ft_strlen_modif(char *str);

//      MLX
void	img_pixel_put(t_data *img, double x, double y, int color);
int		around(float nb);

#endif