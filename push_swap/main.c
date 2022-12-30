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

void	print(t_list **list)
{
	t_list	*liste;
	liste = *(list);
	while (liste)
	{
		printf("%d \n", liste->nb);
		liste = liste->next;
	}
}

int main(int ac, char **av)
{
	int     i;
	t_list  *a_elem;
    t_list  **a_head;
    int	nb;

	i = 1;
	a_elem = NULL;
	if (!parsing(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!generator_pile(&a_elem, nb))
		{
			if (!a_elem)
				return (0);
			ft_lstclear(&a_elem);
			return (0);
		}
		i++;
	}
    a_head = &a_elem;
	print(&a_elem);
    printf("GOING FOR A CHANGE\n");
    a_head = sa(a_head);
    print(a_head);
}