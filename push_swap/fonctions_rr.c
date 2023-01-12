/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:37:48 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:23:34 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a_head, int flag)
{
	t_list	*head;
	t_list	*last;
	t_list	*blast;

	head = *(a_head);
	if (head && head->next)
	{
		last = ft_lstlast(head);
		blast = ft_lstbeforelast(head);
		last->next = head;
		blast->next = NULL;
		*(a_head) = last;
	}
	if (flag == 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b_head, int flag)
{
	t_list	*head;
	t_list	*last;
	t_list	*blast;

	head = *(b_head);
	if (head && head->next)
	{
		last = ft_lstlast(head);
		blast = ft_lstbeforelast(head);
		last->next = head;
		blast->next = NULL;
		*(b_head) = last;
	}
	if (flag == 0)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a_head, t_list **b_head)
{
	rra(a_head, 1);
	rrb(b_head, 1);
	ft_putstr_fd("rrr\n", 1);
}
