/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:24:56 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:29:15 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upper_second_half(t_struct elem, t_list **stack, t_list **tmp, int n)
{
	while (elem.p < n)
	{
		rra(stack, 0);
			elem.p++;
	}
	while (elem.rang)
	{
		rb(tmp, 0);
		elem.rang--;
	}
}

void	lower_second_half(t_struct elem, t_list **stack, t_list **tmp, int n)
{
	while (elem.rang && elem.p < n)
	{
		rrr(stack, tmp);
		elem.rang--;
		elem.p++;
	}
	while (elem.rang)
	{
		rrb(tmp, 0);
		elem.rang--;
	}
	while (elem.p < n)
	{
		rra(stack, 0);
		elem.p++;
	}
}

void	upper_first_half(t_struct elem, t_list **stack, t_list **tmp)
{
	while (elem.rang && elem.p)
	{
		rr(stack, tmp);
		elem.rang--;
		elem.p--;
	}
	while (elem.p)
	{
		ra(stack, 0);
		elem.p--;
	}
	while (elem.rang)
	{
		rb(tmp, 0);
		elem.rang--;
	}
}

void	lower_first_half(t_struct elem, t_list **stack, t_list **tmp)
{
	while (elem.p)
	{
		ra(stack, 0);
		elem.p--;
	}
	while (elem.rang)
	{
		rrb(tmp, 0);
		elem.rang--;
	}
}

void	moves(t_struct elem, t_list **stack, t_list **tmp)
{
	int	n;

	n = ft_lstsize(*stack);
	if (elem.half_s == 1)
	{
		if (elem.half_t == 1)
			upper_first_half(elem, stack, tmp);
		else
			lower_first_half(elem, stack, tmp);
		pa(stack, tmp);
	}
	else
	{
		if (elem.half_t == 1)
			upper_second_half(elem, stack, tmp, n);
		else
			lower_second_half(elem, stack, tmp, n);
		pa(stack, tmp);
	}
}
