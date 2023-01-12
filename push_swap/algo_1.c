/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:46:46 by alvina            #+#    #+#             */
/*   Updated: 2023/01/12 17:18:35 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	create_elem(t_list *stack, t_list *tmp, t_list *head)
{
	t_struct	elem;

	elem.half_t = what_half(head, tmp->nb, 0);
	elem.rang = find_rang(elem.half_t, tmp->nb, head);
	elem.p = comparator(tmp->nb, stack);
	elem.half_s = what_half(stack, elem.p, 1);
	elem.nb_move = move_counter(elem.p, elem.rang, stack);
	return (elem);
}

t_struct	choice(t_list *stack, t_list *tmp)
{
	t_struct	best;
	t_struct	curr;
	t_list		*head;
	int			i;

	i = 0;
	head = tmp;
	while (tmp)
	{	
		curr = create_elem(stack, tmp, head);
		if (i == 0 || best.nb_move >= curr.nb_move)
			best = curr;
		tmp = tmp->next;
		i++;
	}
	return (best);
}

void	decision_maker(t_list **stack, t_list **tmp)
{
	t_struct	needle;

	needle = choice(*stack, *tmp);
	moves(needle, stack, tmp);
}
