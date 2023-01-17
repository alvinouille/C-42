/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:49:01 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/17 15:59:53 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int             nb;
    int             eof;
    struct s_list   *next;
}   t_list;

t_list	*ft_lstlast(t_list *lst);
int     ft_atoi(char nptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

#endif
