/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_s_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:15 by alvina            #+#    #+#             */
/*   Updated: 2023/01/12 17:24:55 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a_head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *(a_head);
	if (first && first->next)
	{
		second = first->next;
		third = second->next;
		first->next = third;
		second->next = first;
		*(a_head) = second;
	}
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **b_head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *(b_head);
	if (first && first->next)
	{
		second = first->next;
		third = second->next;
		first->next = third;
		second->next = first;
		*(b_head) = second;
	}
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_list **a_head, t_list **b_head)
{
	sa(a_head);
	sb(b_head);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_list **a_head, t_list **b_head)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *(a_head);
	head_b = *(b_head);
	if (head_b)
	{
		*(b_head) = head_b->next;
		head_b->next = head_a;
		*(a_head) = head_b;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a_head, t_list **b_head)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = *(a_head);
	head_b = *(b_head);
	if (head_a)
	{
		*(a_head) = head_a->next;
		head_a->next = head_b;
		*(b_head) = head_a;
	}
	ft_putstr_fd("pb\n", 1);
}
