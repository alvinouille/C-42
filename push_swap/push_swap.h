/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:26:45 by marvin            #+#    #+#             */
/*   Updated: 2022/12/22 19:26:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct  s_list
{
    int             nb;
    struct s_list   *next;
}   t_list;

//      UTILS
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
t_list	*ft_lstnew(void *nb);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int	    ft_atoi(const char *nptr);

//      PUSH_SWAP

#endif