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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

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
