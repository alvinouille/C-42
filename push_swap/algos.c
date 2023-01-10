/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:46:46 by alvina            #+#    #+#             */
/*   Updated: 2023/01/10 17:51:34 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	first(t_list **stack_a, t_list **stack_tmp)
// {
// 	t_list	*a;
// 	t_list	*tmp;
// 	int		k;

// 	k = 0;
// 	a = *(stack_a);
// 	tmp = *(stack_tmp);
// 	pb(&a, &tmp);
// 	while (a)
// 	{
// 		k = a->nb;
// 		if (k < tmp->nb)
// 		{
// 			ra(&a);
// 			while (tmp)
// 			{
// 				if (k < tmp->nb)
// 					pa(&a, &tmp);
// 				else
// 					break;
// 			}
// 			rra(&a);
// 			pb(&a, &tmp);
// 		}
// 		else
// 			pb(&a, &tmp);
// 	}
// 	while (tmp)
// 		pa(&a, &tmp);
// 	*(stack_a) = a;
// }

int find_i(t_list *stack, int needle)
{
    int i;

    i = 0;
	// printf("yooooooooo");
    while (stack)
    {
		// printf("stack = %d\n", stack->nb);
        if (stack->nb == needle)
            return (i);
        stack = stack->next;
        i++;
    }
    return (-1);
}

// t_list	*find_lst(t_list *list, int needle)
// {
// 	int i;

//     i = 0;
// 	// printf("yooooooooo");
//     while (list)
//     {
//         if (list->nb == needle)
//             return (list);
//         list = list->next;
//     }
//     return (NULL);
// }

// void	three(t_list **stack)
// {
// 	t_list	*n1;
// 	t_list	*n2;
// 	t_list	*n3;

// 	n1 = *(stack);
// 	n2 = n1->next;
// 	n3 = n2->next;
// 	if (n1->nb < n2->nb)
// 	{
// 		if (n2->nb < n3->nb)
// 			return ;
// 		else
// 		{
// 			if (n3->nb < n1->nb)
// 				rra(stack);
// 			else
// 			{
// 				rra(stack);
// 				sa(stack);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		if (n2->nb < n3->nb)
// 		{
// 			if (n3->nb < n1->nb)
// 				ra(stack);
// 			else
// 				sa(stack);
// 		}
// 		else
// 		{
// 			ra(stack);
// 			sa(stack);
// 		}
// 	}
// }

int	what_half(t_list *list, int needle)
{
	int n;
	int mid;
	
	n = ft_lstsize(list);
	if (n % 2 == 0)
		mid = n / 2;
	else
		mid = (n + 1) /2;
	if (find_i(list, needle) <= mid)
		return (1);
	return (2);	
}

// count how many moves are necessary to place tmp->nb (first / last if (e)) into stack at position p
// tab[0] = nb moves, tab[1] = if it's move of first(1) or second half(2)
int	move_counter(int p, int e, t_list *stack)
{
	int	n;
	int mid;
// printf("p = %d\n", p);
// printf("e = %d\n", e);
	n = ft_lstsize(stack);
// printf("n = %d\n", n);
	if (n % 2 == 0)
		mid = n / 2;
	else
		mid = (n + 1) /2;
	if (p <= mid)
		return (p + 1 + e);
	return (n - p + 1 + e);
}

// 	do actions necessary to place tmp->nb at position p in the second_half of stack, with one move sup if last in tmp (to become first) before being push
void	second_half_moves(int p, int e, t_list **stack, t_list **tmp)
{
	int n;

	n = ft_lstsize(*stack);
	while (p != n)
	{
		rra(stack);
		p++;
	}
	while (e)
	{
		rrb(tmp);
		e--;
	}
	pa(stack, tmp);
}

// do actions necessary to place tmp->nb at position p in the first_half of stack, with one move sup if last in tmp (to become first) before being push
void	first_half_moves(int p, int e, t_list **stack, t_list **tmp)
{
	while (p)
	{
		ra(stack);
		p--;
	}
	while (e)
	{
		rrb(tmp);
		e--;
	}
	pa(stack, tmp);	
}

int	find_rang(int half, int needle, t_list *list)
{
	int rang;
	int size;

	rang = find_i(list, needle);
	size = ft_lstsize(list);
	if (half == 1)
		return (rang);
	return (size - rang + 1);
}

int ultime_decision_maker(t_list *stack, t_list *tmp)
{
	int needle;
	int half;
	int rang;
	int p;
	int nb_move;
	t_list *head;
	int best;

	needle = (-1);
	head = tmp;
	while (tmp)
	{	
		half = what_half(head, tmp->nb);  //what half
		rang = find_rang(half, tmp->nb, head);  //rang
		p = comparator(tmp->nb, stack); //position
		nb_move = move_counter(p, half, stack); //moves
		printf("\nrag = %d\npostion visee = %d\nnb coups = %d, nb = %d\n", rang, p, nb_move, tmp->nb);
		if (needle == -1)
			best = nb_move;
		if (best >= nb_move)
		{
			// printf("here\n");
			best = nb_move;
			needle = tmp->nb;
		}
		tmp = tmp->next;
	}
	// printf("needle = %d\n", needle);
	return (needle);
}

// decides either first or last extremity has the less nber of moves and so does the matching actions with it
void	decision_maker(t_list **stack, t_list **tmp)
{
	int needle;
	int half;
	int rang;
	int p;
	int nb_move;
	t_list *head_s = *stack;
	t_list *head_t = *tmp;
	
	printf("size = %d\n", ft_lstsize(*tmp));
	needle = ultime_decision_maker(head_s, head_t);
	half = what_half(head_t, needle);  //what half
	rang = find_rang(half, needle, head_t);  //rang
	p = comparator(needle, head_s); //position
	nb_move = move_counter(p, rang, head_s);
	printf("\nrag = %d\npostion visee = %d\nnb coups = %d, nb = %d\n", rang, p, nb_move, needle);
	printf("- - -");
	if (half == 1)
		first_half_moves(p, rang, stack, tmp);
	else
		second_half_moves(p, rang, stack, tmp);
}

//	compare the extremity given with stack to find it position(p) and return it
int	comparator(int nb, t_list *stack)
{
	int p;	
	int	n1;
	int n2;

	p = 0;
	if (nb < smaller(stack))
		return find_i(stack, bigger(stack)) + 1;
	// printf("nb = %d, stack nb = %d\n", nb, stack->nb);
	if (nb < (stack)->nb && nb > (ft_lstlast(stack)->nb))
		return (p);
	p++;
	while ((stack)->next)
	{
		// printf("nb = %d, stack nb = %d\n", nb, stack->nb);
		n1 = (stack)->nb;
		n2 = (stack)->next->nb;
		if (nb > n1 && nb < n2)
			return (p);
		(stack) = (stack)->next;
		p++;
	}
	// printf("\t\t - - -\n");
	return (p);
}
			
// int	mediane(int *tab, int n)
// {
// 	int	val1;
// 	int	val2;

// 	if (n % 2 != 0)
//         return (tab[(n + 1) /2 -1]);
//     val1 = tab[n / 2 -1]; 
// 	val2 = tab[n / 2];
//     return ((val1 + val2) / 2);
// }

// get a tab with smallest(tab[0]), biggest(tab[2]) and medium nb(tab[1])
// int	*cheater(t_list **stack, int extr[3])
// {
// 	int *sort;
// 	int	i;
// 	int n;

// 	n = ft_lstsize(*stack);
// 	sort = malloc(sizeof(int) * n);
// 	if (!sort)
// 		return (NULL);
// 	while (i < n -1)
// 	{
// 		sort[i] = (*stack)->nb;
// 		printf("tab = %d\n", sort[i]);
// 		(*stack) = (*stack)->next;
// 		i++;
// 	}
// 	// ft_sort_int_tab(sort, n);
// 	extr[0] = sort[0];
// 	extr[2] = sort[n - 1];
// 	extr[1] = mediane(sort, n);
// 	free(sort);
// 	return (extr);
// }

int	bigger(t_list *list)
{
	int	bigger;
	int curr;

	bigger = 0;
	while (list)
	{
		curr = (list)->nb;
		if (curr > bigger)
			bigger = curr;
		(list) = (list)->next;
	}
	return (bigger);
}

int	smaller(t_list *list)
{
	int	smaller;
	int curr;

	// if(!list)
	// 	return (-1);
	smaller = (list)->nb;
	while (list)
	{
		curr = (list)->nb;
		if (curr < smaller)
			smaller = curr;
		(list) = (list)->next;
	}
	return (smaller);
}

// depending on where the smallest nb is, ra or rra to leveling up to the top of stack
void	finisher(t_list **stack)
{
	int smallest;
	int	n;

	smallest = find_i(*stack, smaller(*stack));
	n = ft_lstsize(*stack);
	if ((n % 2 == 0 && smallest <=  n / 2) ||
		(n % 2 != 0 && smallest <= (n + 1)/2))
	{
		while (smallest)
		{
			ra(stack);
			smallest--;
		}
	}
	else
	{
		while (smallest <= n)
		{
			rra(stack);
			smallest++;
		}
	}
}

void	setuper(t_list **stack, t_list **tmp)
{
	int biggest;
	int	i;
	int size;

	i = 0;
	size = ft_lstsize(*stack);
	biggest = find_i(*stack, bigger(*stack));
	while (size > 1)
	{
		if (i == biggest)
			ra(stack);
		else
			pb(stack, tmp);
		size = ft_lstsize(*stack);
		i++;
	}
}
