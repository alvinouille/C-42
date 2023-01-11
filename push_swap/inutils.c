/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:23:04 by alvina            #+#    #+#             */
/*   Updated: 2023/01/10 16:23:27 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *creation()
{
    int i = 1;
    t_list  *head;
    t_list  *list;

    head = ft_lstnew(i);
    while (i++ < 5)
    {
        list = ft_lstnew(i);
        ft_lstadd_back(&head, list);
    }
    return (head);
}

void    print(t_list *lista, t_list *listb)
{
    printf("\n\n\n");
    printlist(lista, 'a');
    printlist(listb, 'b');
}

void	printlist(t_list *liste, char a)
{
	while (liste)
	{
		printf("%d \n", liste->nb);
		liste = liste->next;
	}
    printf("-\n%c\n\n", a);
}