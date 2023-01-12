/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:15:26 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:15:00 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
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
	return (*lst);
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
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
		ft_lstdelone(head);
		head = body;
	}
	(*lst) = NULL;
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr[i])
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	if (!tab)
		return ;
	while (i < size -1)
	{
		if ((tab[i]) > (tab[i +1]))
		{
			tmp = (tab[i]);
			(tab[i]) = (tab[i +1]);
			(tab[i +1]) = tmp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}
