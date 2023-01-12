/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:35:08 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:10:49 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger(t_list *list)
{
	int	bigger;
	int	curr;

	bigger = 0;
	while (list)
	{
		curr = list->nb;
		if (curr > bigger)
			bigger = curr;
		list = list->next;
	}
	return (bigger);
}

int	smaller(t_list *list)
{
	int	smaller;
	int	curr;

	smaller = list->nb;
	while (list)
	{
		curr = list->nb;
		if (curr < smaller)
			smaller = curr;
		list = list->next;
	}
	return (smaller);
}

int	find_rang(int half, int needle, t_list *list)
{
	int	rang;
	int	size;

	rang = find_i(list, needle);
	size = ft_lstsize(list);
	if (half == 1)
		return (rang);
	return (size - rang);
}
