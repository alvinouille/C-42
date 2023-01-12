/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:38:05 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:22:06 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finisher(t_list **stack)
{
	int	smallest;
	int	n;
	int	half;

	smallest = find_i(*stack, smaller(*stack));
	n = ft_lstsize(*stack);
	half = what_half(*stack, smallest, 1);
	if (half == 1)
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

int	move_counter(int position, int rang, t_list *stack)
{
	int	n;
	int	mid;

	n = ft_lstsize(stack);
	if (n % 2 == 0)
		mid = n / 2;
	else
		mid = (n + 1) / 2;
	if (position <= mid)
		return (position + 1 + rang);
	return (n - position + 1 + rang);
}

int	comparator(int nb, t_list *stack)
{
	int	p;	
	int	n1;
	int	n2;

	p = 1;
	if (nb < smaller(stack))
	{
		if (bigger(stack) == ft_lstlast(stack)->nb)
			return (0);
		return (find_i(stack, bigger(stack)) + 1);
	}
	if (nb < (stack)->nb && nb > ft_lstlast(stack)->nb)
		return (0);
	while (stack->next)
	{
		n1 = stack->nb;
		n2 = stack->next->nb;
		if (nb > n1 && nb < n2)
			return (p);
		stack = stack->next;
		p++;
	}
	return (p);
}
