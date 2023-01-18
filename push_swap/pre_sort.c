/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:36:13 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/17 09:32:54 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_repartiter(t_list **stack, t_list**tmp, int *tab, int size)
{
	int	q1;
	int	flag;

	flag = 0;
	q1 = quartile(tab, size, 1);
	if ((*stack)->nb < q1)
		flag = 1;
	pb(stack, tmp);
	if (flag == 1)
		rb(tmp, 0);
}

void	second_repartiter(t_list **stack, t_list**tmp, int *tab, int size)
{
	int	flag;
	int	q3;

	flag = 0;
	q3 = quartile(tab, size, 3);
	if ((*stack)->nb < q3)
		flag = 1;
	pb(stack, tmp);
	if (flag == 1)
		rb(tmp, 0);
}

void	pre_selection(t_list **stack, t_list **tmp, int size, int n)
{
	int	med;
	int	*tab;

	tab = sorted_tab(*stack);
	if (!tab)
		return ;
	med = mediane(tab, size);
	while (n--)
	{
		if ((*stack)->nb == tab[size -1])
			ra(stack, 0);
		else
		{
			if (n > size)
			{
				if ((*stack)->nb < med)
					first_repartiter(stack, tmp, tab, size);
				else
					ra(stack, 0);
			}
			else
				second_repartiter(stack, tmp, tab, size);
		}
	}
	free(tab);
}
