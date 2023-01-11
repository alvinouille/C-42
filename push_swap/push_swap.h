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
int	    ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
t_list	*ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
long	ft_atoi(const char *nptr);
void	ft_sort_int_tab(int *tab, int size);

//      INUTILS
t_list  *creation();
void	printlist(t_list *liste, char a);
void    print(t_list *lista, t_list *listb);

//      FONCTIONS
void    sa(t_list **a_head);
void    sb(t_list **b_head);
void    ss(t_list **a_head, t_list **b_head);
void	ra(t_list **a_head, int flag);
void	rb(t_list **b_head, int flag);
void    rr(t_list **a_head, t_list **b_head);
void	rra(t_list **a_head, int flag);
void	rrb(t_list **b_head, int flag);
void    rrr(t_list **a_head, t_list **b_head);
void	pa(t_list **a_head, t_list **b_head);
void	pb(t_list **a_head, t_list **b_head);

//      PUSH_SWAP
void	*generator_pile(t_list **a_stack, int nb);
int     parsing(int ac, char **av);

//      ALGOS
int	what_half(t_list *list, int needle, int flag);
void	three(t_list **stack);
void	five(t_list **stack, t_list **tmp);
int     find_i(t_list *stack, int needle);
int quartile(int *tab, int n, int q);
int     mediane(int *tab, int n);
int	*sorted_tab(t_list *stack);
void    first_repartiter(t_list **stack, t_list**tmp, int *tab, int size);
void    second_repartiter(t_list **stack, t_list**tmp, int *tab, int size);
void    pre_selection(t_list **stack, t_list **tmp);
int	    smaller(t_list *list);
int	    bigger(t_list *list);
void	finisher(t_list **stack);
int ultime_decision_maker(t_list *stack, t_list *tmp);
void	decision_maker(t_list **stack, t_list **tmp);
int	    comparator(int nb, t_list *stack);
int	move_counter(int p, int e, t_list *stack);
void	first_half_moves(int p, int e, t_list **stack, t_list **tmp);
void	second_half_moves(int p, int e, t_list **stack, t_list **tmp);

#endif