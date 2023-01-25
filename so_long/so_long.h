/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:20:14 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/25 20:58:01 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "get_next_line/get_next_line.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_adr {
	void	*player;
	void	*collec;
	void	*border;
	void	*exit;
	void	*background;
}				t_adr;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		length;
	int 	width;
    char     **tab;
	t_adr	img;
}				t_vars;

//      UTILS
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);

//      PARSING
int is_ok(char **tab, char **tmp);
int is_rectangular(char **tab);
int cep_check(char **tab);
int wrong_char(char **tab);
int check_col(char **tab);
int check_line(char *str);
int is_closed(char **tab);
int is_valid(char **tab);
void	print(char **tab);

//		MOVE
void    move_up(t_vars *vars);
void    move_down(t_vars *vars);
void    move_right(t_vars *vars);
void    move_left(t_vars *vars);

//		DISPLAY_MAP
void    display_img(char c, int x, int y, t_vars *vars);
void    display_game(char **tab, t_vars *vars);

#endif
