/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:31:52 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/12 17:34:49 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing_doublon(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] == '0')
		j++;
	while (s2[i] == '0')
		i++;
	if (s1[j] == s2[i])
	{
		while (s1[j] && s2[i] && s1[j] == s2[i])
		{
			j++;
			i++;
		}
		if (s1[j] == '\0' && s2[i] == '\0')
			return (1);
	}
	return (0);
}

int	checker_doublon(int ac, char **av, char *str, int curr)
{
	int	k;

	k = 0;
	while (k < ac)
	{
		if (k != curr)
		{
			if (parsing_doublon(str, av[k]))
				return (1);
		}
		k++;
	}
	return (0);
}

int	checker(int ac, char **av, long nb)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
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
		i++;
	}
	return (1);
}

int	parsing(int ac, char **av, t_list **stack)
{
	int	nb;
	int	i;

	i = 1;
	if (ac == 1)
		return (0);
	if (!checker(ac, av, 0))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!generator_pile(stack, nb))
		{
			if (!stack)
				return (0);
			return (ft_exit(stack, NULL));
		}
		i++;
	}
	if (is_sorted(*stack))
		return (ft_exit(stack, NULL));
	return (1);
}
