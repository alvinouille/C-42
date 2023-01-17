/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:34:47 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/17 16:05:19 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*head;
	t_list	*body;

	if (!lst || !(*lst))
		return ;
	head = (*lst);
	while (head)
	{
		body = head->next;
		free(head);
		head = body;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		if (lst && new)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}

int	ft_atoi(char nptr)
{
	int		i;
	long	nb;


	i = 0;
	nb = 0;

    
	nb = nb * 10 + (nptr - 48);
	return (nb * neg);
}