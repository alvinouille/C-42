/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:36:53 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 16:38:12 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a_head, int flag)
{
	t_list	*last;
	t_list	*second;
	t_list	*head;

	head = *(a_head);
	if (head && head->next)
	{
		second = head->next;
		last = ft_lstlast(head);
		last->next = head;
		head->next = NULL;
		*(a_head) = second;
	}
	if (flag == 0)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b_head, int flag)
{
	t_list	*last;
	t_list	*second;
	t_list	*head;

	head = *(b_head);
	if (head && head->next)
	{
		second = head->next;
		last = ft_lstlast(head);
		last->next = head;
		head->next = NULL;
		*(b_head) = second;
	}
	if (flag == 0)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **a_head, t_list **b_head)
{
	ra(a_head, 1);
	rb(b_head, 1);
	ft_putstr_fd("rr\n", 1);
}
