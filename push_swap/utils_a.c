/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:17:55 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:29:52 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_i(t_list *stack, int needle)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->nb == needle)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	what_half(t_list *list, int needle, int flag)
{
	int	n;
	int	mid;

	n = ft_lstsize(list);
	if (n % 2 == 0)
		mid = n / 2;
	else
		mid = (n + 1) / 2;
	if (flag == 0)
	{
		if (find_i(list, needle) + 1 <= mid)
			return (1);
		return (2);
	}
	if (needle <= mid)
		return (1);
	return (2);
}

int	mediane(int *tab, int n)
{
	int	val1;
	int	val2;

	if (n % 2 != 0)
		return (tab[(n + 1) / 2 - 1]);
	val1 = tab[n / 2 - 1];
	val2 = tab[n / 2];
	return ((val1 + val2) / 2);
}

int	quartile(int *tab, int n, int q)
{
	int	index;

	if (q == 1)
		index = n / 4 - 1;
	else
		index = n / 4 * 3 - 1;
	return (tab[index]);
}

int	*sorted_tab(t_list *stack)
{
	int	*sort;
	int	i;
	int	n;

	i = 0;
	n = ft_lstsize(stack);
	sort = malloc(sizeof(int) * n);
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
