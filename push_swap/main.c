/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:26:51 by marvin            #+#    #+#             */
/*   Updated: 2022/12/22 19:26:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	parsing(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_atoi(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*generator_pile(t_list **a_elem, int *nb)
{
	t_list		*new;

	new = ft_lstnew(nb);
	if (!new)
		return (NULL);
	ft_lstadd_back(a_stack, new);
	return (a_stack);
}

void	print(t_list **list)
{
	while (list)
	{
		printf("%d \n", list->nb);
		list = list->next;
	}
}

int main(int ac, char **av)
{
	int     i;
	t_list  *a_elem;

	i = 1;
	if (!parsing(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i++ < ac)
	{
		if (!generator_pile(&a_elem, ft_atoi(av[i])))
		{
			if (!a_elem)
				return (0);
			ft_lstclear(&a_elem);
			return (0);
		}
	}
	print(&a_elem);
}