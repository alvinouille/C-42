/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:19:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 22:08:56 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_two(t_list **stack)
{
	sa(stack);
	return ;
}

void	five(t_list **stack, t_list **tmp, int i)
{
	int	size;
	int	biggest;
	int	s;

	s = ft_lstsize(*stack);
	biggest = bigger(*stack);
	if (i == 2)
		return (checker_two(stack));
	i = i - 3;
	while (s > 3)
	{
		if ((*stack)->nb == biggest)
			ra(stack, 0);
		else
			pb(stack, tmp);
		s = ft_lstsize(*stack);
	}
	three(stack);
	size = ft_lstsize(*tmp);
	while (size)
	{
		decision_maker(stack, tmp);
		size--;
	}
	finisher(stack);
}

void	first_case(t_list **stack, int a, int b)
{
	if (b < a)
		rra(stack, 0);
	else
	{
		rra(stack, 0);
		sa(stack);
	}
}

void	second_case(t_list **stack, int a, int b, int c)
{
	if (b < c)
	{
		if (c < a)
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
			first_case(stack, n1->nb, n3->nb);
	}
	else
		second_case(stack, n1->nb, n2->nb, n3->nb);
}
