/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:56:07 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/03 17:40:36 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "get_next_line.h"
# include <math.h>
# define LENGTH 1920
# define WIDTH 1080

typedef struct s_needle
{
	double	x;
	double	y;
}	t_needle;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	int			**tab;
	int			width;
	int			echelle;
	t_point		origine;
	t_needle	**map;
	int			*leng;
}				t_vars;

//			UTILS
char		*ft_strjoin(char *s1, char *s2, int i, int j);
int			ft_atoi(char *nptr);
char		*ft_strnstr(const char *big, const char *little, size_t len);
void		ft_putstr_fd(char *s, int fd);
int			around(float nb);
int			ft_isalnum(int c);
void		print(int **tab, int width,	int *leng);
int			tab_width(char *str, char c);

//			MLX
void		img_pixel_put(t_data *img, double x, double y, int color);
void		mlx(t_vars vars);
int			key_hook(int keycode, t_vars *vars);
int			fdf(t_vars *vars);
int			closing_mouse(t_vars *vars);
int			closing_key(int keycode, t_vars *vars);

//		BRASENHAM
void		first(t_data img, t_needle curr, t_needle next);
void		second(t_data img, t_needle curr, t_needle next);
void		vertical(t_data	img, t_needle curr, t_needle next);
void		fifth(t_data img, t_needle curr, t_needle next);
void		sixth(t_data img, t_needle curr, t_needle next);
void		third(t_data img, t_needle curr, t_needle next);
void		fourth(t_data img, t_needle curr, t_needle next);
void		eight(t_data img, t_needle curr, t_needle next);
void		seventh(t_data img, t_needle curr, t_needle next);
void		bresenham(t_data img, t_needle curr, t_needle next);

//			TRASHING
void		such_a_quitter(t_vars *vars, int flag);
void		cleaning_tab(t_vars *vars);
void		clean_mlx(t_vars *vars);
void		freeer(char *s1, char *s2);

//			PARSING
int			split_tab(char *s, char c, t_vars *vars);
char		*gnl(int fd);
int			arg_check(int ac, char **av);
void		free_tab(int **tab, int j);

//			TRACING
void		tracing(t_vars vars, int i, int j);
t_needle	**create(int *length, int width, t_vars *vars);
void		quadrillage(t_vars *vars);
void		black_screen(t_vars *vars);
t_needle	projection(t_point curr, t_vars *vars);

#endif
