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

int	checker_doublon(int ac, char **av, char *str, int curr)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (k < ac)
	{
		if (k != curr)
		{
			while (str[j] == '0')
				j++;
			while (av[k][i] == '0')
				i++;
			if (str[j] == av[k][i])
			{
				while (str[j] && av[k][i] && str[j] == av[k][i])
				{
					j++;
					i++;
				}
				if (str[j] == '\0' && av[k][i] == '\0')
					return (1);
			}
			j = 0;
			i = 0;
		}
		k++;
	}
	return (0);
}

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
		if (checker_doublon(ac, av, av[i], i))
			return (0);
		while (av[i][j])
		{
			if ((av[i][j] < 48 || av[i][j] > 57) && av[i][j] != '-')
				return (0);
			j++;
		}
		j = 0;
		if (av[i][j] != '0')
		{
			nb = ft_atoi(av[i]);
			if (!nb || nb > 2147483647 || nb < -2147483648)
				return (0);
		}
		else
			nb = 0;
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
	t_list  *stack;
	t_list	*tmp;
	int	nb;
	int size;

	i = 1;
	stack = NULL;
	tmp = NULL;
	if (ac == 1)
		return (0);
	if (!parsing(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i < ac)
	{  
		nb = ft_atoi(av[i]);
		if (!generator_pile(&stack, nb))
		{
			if (!stack)
				return (0);
			ft_lstclear(&stack);
			return (0);
		}
		i++;
	}
	if (ac == 4)
	{
		three(&stack);
		ft_lstclear(&stack);
	}
	else if (ac == 6)
	{
		five(&stack, &tmp);
	}
	else
	{
		pre_selection(&stack, &tmp);
		size = ft_lstsize(tmp);
		while (size)
		{
			decision_maker(&stack, &tmp);
			size --;
		}
		finisher(&stack);
		ft_lstclear(&stack);
		ft_lstclear(&tmp);
	}
}