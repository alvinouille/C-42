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
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}	t_list;

typedef struct s_struct
{
	int	half_t;
	int	half_s;
	int	rang;
	int	p;
	int	nb_move;
}	t_struct;

//      UTILS FONCTIONS
void		ft_putstr_fd(char *s, int fd);
t_list		*ft_lstnew(int nb);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstbeforelast(t_list *lst);
t_list		*ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
long		ft_atoi(const char *nptr);
void		ft_sort_int_tab(int *tab, int size);

//      FONCTIONS
void		sa(t_list **a_head);
void		sb(t_list **b_head);
void		ss(t_list **a_head, t_list **b_head);
void		ra(t_list **a_head, int flag);
void		rb(t_list **b_head, int flag);
void		rr(t_list **a_head, t_list **b_head);
void		rra(t_list **a_head, int flag);
void		rrb(t_list **b_head, int flag);
void		rrr(t_list **a_head, t_list **b_head);
void		pa(t_list **a_head, t_list **b_head);
void		pb(t_list **a_head, t_list **b_head);

//      PARSING
void		*generator_pile(t_list **a_stack, int nb);
int			is_sorted(t_list *stack);
int			parsing_doublon(char *s1, char *s2);
int			checker_doublon(int ac, char **av, char *str, int curr);
int			checker(int ac, char **av, long nb);
int			ft_exit(t_list **stack, t_list **tmp);
int			parsing(int ac, char **av, t_list **stack);

//      MOVES
void		upper_first_half(t_struct elem, t_list **stack, t_list **tmp);
void		lower_first_half(t_struct elem, t_list **stack, t_list **tmp);
void		upper_second_half(t_struct elem, t_list **stack,
				t_list **tmp, int n);
void		lower_second_half(t_struct elem, t_list **stack,
				t_list **tmp, int n);
void		moves(t_struct elem, t_list **stack, t_list **tmp);

//      SMALL ALGOS
void		first_case(t_list **stack, int a, int b);
void		second_case(t_list **stack, int a, int b, int c);
void		checker_two(t_list **stack);
void		three(t_list **stack);
void		five(t_list **stack, t_list **tmp, int i);

//      PRE SORT AND FINISHER ALGOS
void		first_repartiter(t_list **stack, t_list**tmp, int *tab, int size);
void		second_repartiter(t_list **stack, t_list**tmp, int *tab, int size);
void		pre_selection(t_list **stack, t_list **tmp, int size, int n);
void		finisher(t_list **stack);

//      MAIN ALGOS
int			comparator(int nb, t_list *stack);
int			move_counter(int p, int e, t_list *stack);
t_struct	create_elem(t_list *stack, t_list *tmp, t_list *head);
t_struct	choice(t_list *stack, t_list *tmp);
void		decision_maker(t_list **stack, t_list **tmp);

//      UTILS ALGOS
int			smaller(t_list *list);
int			bigger(t_list *list);
int			quartile(int *tab, int n, int q);
int			mediane(int *tab, int n);
int			*sorted_tab(t_list *stack);
int			find_rang(int half, int needle, t_list *list);
int			find_i(t_list *stack, int needle);
int			what_half(t_list *list, int needle, int flag);

#endif