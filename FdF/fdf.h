/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:49:01 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/18 17:01:07 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "get_next_line/get_next_line.h"

typedef struct s_point
{
    int x;
    int y;
}   t_point;


typedef struct s_list
{
    int             nb;
    t_point         c;
    struct s_list   *beside;
    struct s_list   *next;
}   t_list;

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
    t_data    img;
}				t_vars;

// typedef struct s_args
// {
//     t_point start;
//     t_vars mlx;
// }   t_args;

t_list	*ft_lstlast(t_list *lst);
int     ft_atoi(char *nptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

void    print(t_list *lst, int dim[2]);
void    print2(t_list *lst, int dim[2]);

void    trace_line(t_data img, int x, int y, int echelle);
void    trace_col(t_data img, int x, int y, int echelle);
int closing_key(int keycode, t_vars *vars);
int closing_mouse(t_vars *vars);
// void    initialising(t_point *name, int x, int y);

#endif
