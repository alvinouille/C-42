/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:26:58 by marvin            #+#    #+#             */
/*   Updated: 2022/12/22 19:26:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
#include <stdio.h>
t_list	*ft_lstnew(int nb)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list)
	{
		list->nb = nb;
		list->next = NULL;
	}
	return (list);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		i;

	list = lst;
	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstbeforelast(t_list *lst)
{
	while (lst && lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

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
	while (i < size)
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




