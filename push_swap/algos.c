/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:46:46 by alvina            #+#    #+#             */
/*   Updated: 2023/01/11 21:22:46 by ale-sain         ###   ########.fr       */
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

// void	five(t_list **stack, t_list **tmp)
// {
// 	int p;
// 	int half;
// 	int i;

// 	i = 0;
// 	pb(stack, tmp);
// 	pb(stack, tmp);
// 	three(stack);
// 	while (i < 2)
// 	{
// 		p = comparator((*tmp)->nb, *stack);
// 		half = what_half(*stack, p, 1);
// 		if (half == 1)
// 			first_half_moves(p, 0, stack, tmp);
// 		else
// 			second_half_moves(p, 0, stack, tmp);
// 		i++;
// 	}
// }

void	three(t_list **stack)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	n1 = *(stack);
	n2 = n1->next;
	n3 = n2->next;
	if (n1->nb < n2->nb)
	{
		if (n2->nb < n3->nb)
			return ;
		else
		{
			if (n3->nb < n1->nb)
				rra(stack, 0);
			else
			{
				rra(stack, 0);
				sa(stack);
			}
		}
	}
	else
	{
		if (n2->nb < n3->nb)
		{
			if (n3->nb < n1->nb)
				ra(stack, 0);
			else
				sa(stack);
		}
		else
		{
			ra(stack, 0);
			sa(stack);
		}
	}
}

int	what_half(t_list *list, int needle, int flag)
{
	int n;
	int mid;
	
	n = ft_lstsize(list);
	if (n % 2 == 0)
		mid = n / 2;
	else
		mid = (n + 1) /2;
	if (flag == 0) //means its about the place in tmp
	{
		if (find_i(list, needle) + 1 <= mid)
			return (1);
		return (2);
	}
	if (needle <= mid) //means its about stack wanted position
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
	if (e < 0)
	{
		while (p < n)
		{
			rra(stack, 0);
			p++;
		}
		e = -e;
		while (e)
		{
			rb(tmp, 0);
			e--;
		}
	}
	else
	{
		while (e && p < n)
		{
			rrr(stack, tmp);
			e--;
			p++;
		}
		while (e)
		{
			rrb(tmp, 0);
			e--;
		}
		while (p < n)
		{
			rra(stack, 0);
			p++;
		}
	}
	pa(stack, tmp);
}

// do actions necessary to place tmp->nb at position p in the first_half of stack, with one move sup if last in tmp (to become first) before being push
void	first_half_moves(int p, int e, t_list **stack, t_list **tmp)
{
	if (e < 0)
	{
		e = -e;
		while (e && p)
		{
			rr(stack, tmp);
			e--;
			p--;
		}
		while (p)
		{
			ra(stack, 0);
			p--;
		}
		while (e)
		{
			rb(tmp, 0);
			e--;
		}
	}
	else
	{
		while (p)
		{
			ra(stack, 0);
			p--;
		}
		while (e)
		{
			rrb(tmp, 0);
			e--;
		}
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
	return (size - rang);
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
		half = what_half(head, tmp->nb, 0);  //what half
		rang = find_rang(half, tmp->nb, head);  //rang
		p = comparator(tmp->nb, stack); //position
		nb_move = move_counter(p, rang, stack); //moves
// printf("\nhalf:%d\nrag = %d\npostion visee = %d\nnb coups = %d, nb = %d\n", half, rang, p, nb_move, tmp->nb);
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
	int half[2];
	int rang;
	int p;
	int nb_move;
	t_list *head_s = *stack;
	t_list *head_t = *tmp;
	
// printf("size = %d\n", ft_lstsize(*tmp));
	needle = ultime_decision_maker(head_s, head_t);
// printf("<<<<<<>>>>>");
	half[0] = what_half(head_t, needle, 0);  //what half
	rang = find_rang(half[0], needle, head_t);  //rang
	p = comparator(needle, head_s); //position
	nb_move = move_counter(p, rang, head_s);
// printf("\nrag = %d\npostion visee = %d\nnb coups = %d, nb = %d\n", rang, p, nb_move, needle);
// printf("- - -");
	half[1] = what_half(*stack, p, 1);
	if (half[0] == 1)
		rang = -rang;
	if (half[1] == 1)
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

	p = 1;
	if (ft_lstsize(stack) == 1)
	{
		if (nb < stack->nb)
			return (0);
		else
			return (1);
	}
	if (nb < smaller(stack))
	{
		if (bigger(stack) == (ft_lstlast(stack))->nb)
			return (0);
		return find_i(stack, bigger(stack)) + 1;
	}
	// printf("nb = %d, stack nb = %d\n", nb, stack->nb);
	if (nb < (stack)->nb && nb > (ft_lstlast(stack)->nb))
		return (0);
	
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
			
int	mediane(int *tab, int n)
{
	int	val1;
	int	val2;

	if (n % 2 != 0)
        return (tab[(n + 1) /2 -1]);
    val1 = tab[n / 2 -1]; 
	val2 = tab[n / 2];
    return ((val1 + val2) / 2);
}

int quartile(int *tab, int n, int q)
{
    int index;
	
	if (q == 1)
		index = n /4 -1;
	else
		index = n /4 *3 -1;
	return (tab[index]);
}

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
			ra(stack, 0);
			smallest--;
		}
	}
	else
	{
		while (smallest < n)
		{
			rra(stack, 0);
			smallest++;
		}
	}
}

int	*sorted_tab(t_list *stack)
{
	int *sort;
	int	i;
	int n;;

	n = ft_lstsize(stack);
	sort = malloc(sizeof(int) * n);
    i = 0;
	if (!sort)
		return (0);
	while (i < n)
	{
		sort[i] = stack->nb;
		stack = stack->next;
		i++;
	}
	ft_sort_int_tab(sort, n);
    return (sort);
}

void    first_repartiter(t_list **stack, t_list**tmp, int *tab, int size)
{
	int q1;
	int flag;

	flag = 0;
	q1 = quartile(tab, size, 1);
    if ((*stack)->nb < q1) //if nb <= med : pb + take it to bottom
        flag = 1;
    pb(stack, tmp);
    if (flag == 1)
        rb(tmp, 0);
}

void    second_repartiter(t_list **stack, t_list**tmp, int *tab, int size)
{
    int flag;
	int q3;

	flag = 0;
	q3 = quartile(tab, size, 3);
    if ((*stack)->nb < q3) //if nb <= med : pb + take it to bottom
        flag = 1;
    pb(stack, tmp);
    if (flag == 1)
        rb(tmp, 0);
}

void    pre_selection(t_list **stack, t_list **tmp)
{
	int med;
	int a;
	int n;
	int size;
	int *tab;

	a = 0;
	tab = sorted_tab(*stack);
	size = ft_lstsize(*stack);
	n = size;
	med = mediane(tab, size);
    while (n)
    {
        if ((*stack)->nb == tab[size -1])
        	ra(stack, 0);
		else
        {
			if (a == 0)
			{
				if ((*stack)->nb < med)
					first_repartiter(stack, tmp, tab, size);
        		else
					ra(stack, 0);
			}
			else
				second_repartiter(stack, tmp, tab, size);
		}
		n--;
		if (n == 0 && a == 0)
		{
			n = size;
			a = 1;
		}
		// print(*stack, *tmp);
    }
	free(tab);
}