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
#include <stdio.h>

typedef struct  s_list
{
    int             nb;
    struct s_list   *next;
}   t_list;

//      UTILS
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
t_list	*ft_lstnew(int nb);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
long	ft_atoi(const char *nptr);

//      INUTILS
t_list  *creation();
void	printlist(t_list **list, char a);
void    print(t_list **lista, t_list **listb);
void	test(t_list **a, t_list **b);

//      FONCTIONS
void    sa(t_list **a_head);
void    sb(t_list **b_head);
void    ss(t_list **a_head, t_list **b_head);
void	ra(t_list **a_head);
void	rb(t_list **b_head);
void    rr(t_list **a_head, t_list **b_head);
void	rra(t_list **a_head);
void	rrb(t_list **b_head);
void    rrr(t_list **a_head, t_list **b_head);
void	pa(t_list **a_head, t_list **b_head);
void	pb(t_list **a_head, t_list **b_head);

//      PUSH_SWAP
void	*generator_pile(t_list **a_stack, int nb);
int     parsing(int ac, char **av);

//      ALGOS
void	first(t_list **stack_a, t_list **stack_tmp);
void	three(t_list **stack);

#endif