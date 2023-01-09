/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:46:46 by alvina            #+#    #+#             */
/*   Updated: 2023/01/07 20:39:16 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first(t_list **stack_a, t_list **stack_tmp)
{
	t_list	*a;
	t_list	*tmp;
	int		k;

	k = 0;
	a = *(stack_a);
	tmp = *(stack_tmp);
	pb(&a, &tmp);
	while (a)
	{
		k = a->nb;
		if (k < tmp->nb)
		{
			ra(&a);
			while (tmp)
			{
				if (k < tmp->nb)
					pa(&a, &tmp);
				else
					break;
			}
			rra(&a);
			pb(&a, &tmp);
		}
		else
			pb(&a, &tmp);
	}
	while (tmp)
		pa(&a, &tmp);
	*(stack_a) = a;
}

int find_i(t_list *stack, int needle)
{
    int i;

    i = 0;
    while (stack)
    {
        if (stack->nb = needle)
            return (i);
        stack = stack->next;
        i++;
    }
    return (-1);
}

// void	selection_sort(t_list **stack_a, t_list **stack_tmp)
// {
    
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
				rra(stack);
			else
			{
				rra(stack);
				sa(stack);
			}
		}
	}
	else
	{
		if (n2->nb < n3->nb)
		{
			if (n3->nb < n1->nb)
				ra(stack);
			else
				sa(stack);
		}
		else
		{
			ra(stack);
			sa(stack);
		}
	}
}

void	repartiter(int p2, t_list **stack, t_list **tmp)
{
	if (p2 == 0)
		pa(stack, tmp);
	else if (p2 == 1)
	{
		ra(stack);
		pa(stack, tmp);
	}
	else if (p2 == 2)
	{
		rra(stack);
		rra(stack);
		pa(stack, tmp);
	}
	else if (p2 == 3)
	{
		rra(stack);
		pa(stack, tmp);
	}
	else
	{
		pa(stack, tmp);
		ra(stack);
	}
	// a generaliser pour size n en supp p1 et 
	//	ra/rra : size - p2/p2
}

void	comparator(t_list **stack, int n, t_list **tmp)
{
	int	n1 = *(stack->nb);
	int n2 = *(stack->next->nb);
	int n3 = *(stack->next->next->nb);
	if (n < n1)
		repartiter(find_i(*(stack), n1), stack, tmp)
	else if (n > n1 && n < n2)
		repartiter(find_i(*(stack), n2), stack, tmp);
	else if (n > n2 && n < n3)
		repartiter(find_i(*(stack), n3), stack, tmp);
	else
		repartiter(3, stack, tmp);
}
void	five(t_list **stack, t_list **tmp)
{
	pb(stack, tmp);
	pb(stack, tmp);
	three(stack);
	int t1 = (*tmp)->nb;
	int t2 = (*tmp)->next->nb;
	if (t1 > n1 && t1 < n2)
	{

	}
}