/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:22:15 by alvina            #+#    #+#             */
/*   Updated: 2023/01/11 21:10:02 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list **a_head)
{
    t_list  *first;
    t_list  *second;
    t_list  *third;

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

void sb(t_list **b_head)
{
    t_list  *first;
    t_list  *second;
    t_list  *third;

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

void    ss(t_list **a_head, t_list **b_head)
{
    sa(a_head);
    sb(b_head);
    ft_putstr_fd("ss\n", 1);
}

void	ra(t_list **a_head, int flag)
{
    t_list  *last;
    t_list  *second;
    t_list  *head;

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
    t_list  *last;
    t_list  *second;
    t_list  *head;

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

void    rr(t_list **a_head, t_list **b_head)
{
    ra(a_head, 1);
    rb(b_head, 1);
    ft_putstr_fd("rr\n", 1);
}

void	rra(t_list **a_head, int flag)
{
    t_list  *head;
    t_list  *last;
    t_list  *blast;

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
    t_list  *head;
    t_list  *last;
    t_list  *blast;

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

void    rrr(t_list **a_head, t_list **b_head)
{
    rra(a_head, 1);
    rrb(b_head, 1);
    ft_putstr_fd("rrr\n", 1);
}

void	pa(t_list **a_head, t_list **b_head)
{
	t_list *head_a;
	t_list *head_b;
	
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
	t_list *head_a;
	t_list *head_b;
	
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