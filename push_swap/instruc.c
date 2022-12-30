/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:24:19 by marvin            #+#    #+#             */
/*   Updated: 2022/12/30 19:24:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  **ra(t_list **a_head)
{
    printf("there\n");
    t_list  *first;
    t_list  *second;
    t_list  *head;

    first = *(a_head);
    printf("<<<<<< first : %d\n", first->nb);
    if (first && first->next)
    {
        second = first->next;
        printf("<<<<<< second 1: %d, head : %d\n", second->nb, (*a_head)->nb);
        first->next = NULL;
        *(a_head) = ft_lstadd_back(&second, first);
        printf("<<<<<< second2 : %d, head : %d\n", second->nb, (*a_head)->nb);
    }
    return (a_head);
}

t_list    **sa(t_list **a_head)
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
        a_head = &second;
    }
    return (a_head);
}

// void    sb(t_list **b_head)
// {
//     t_list  *first;
//     t_list  *second;
//     t_list  *third;

//     first = *(b_head);
//     if (first && first->next)
//     {
//         second = first->next;
//         third = second->next;
//         first->next = third;
//         second->next = first;
//         b_head = &second;
//     }
// }

// void    ss(t_list **a_head, t_list **b_head)
// {
//     sa(a_head);
//     sb(b_head);
// }