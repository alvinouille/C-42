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

int	parsing(int ac, char **av)
{
	int	i;
	int j;
	long nb;

	i = 1;
	j = 0;
	nb = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
				return (0);
			j++;
		}
		j = 0;
		nb = ft_atoi(av[i]);
		if (!nb || nb > 2147483647 || nb < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

void	*generator_pile(t_list **a_stack, int nb)
{
	t_list		*new;

	new = ft_lstnew(nb);
	if (!new)
		return (NULL);
	ft_lstadd_back(a_stack, new);
	return (a_stack);
}

int main(int ac, char **av)
{
	int     i;
	t_list  *a_list;
	t_list	*b_list;
	int	nb;

	i = 1;
	a_list = NULL;
	b_list = NULL;
	if (!parsing(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!generator_pile(&a_list, nb))
		{
			if (!a_list)
				return (0);
			ft_lstclear(&a_list);
			return (0);
		}
		i++;
	}
	// test(&a_list, &b_list);
	// first(&a_list, &b_list);
	three(&a_list);
	printf("\n\n---------- RESULTS ----------");
	print(&a_list, &b_list);
	ft_lstclear(&b_list);
	ft_lstclear(&a_list);
}