/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:22:08 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/11 17:02:41 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		follower(t_list *stack, int *tab, int size)
{
	int i;

	i = 0;
	while (i < (size -1))
	{
		if (stack->nb == tab[i] && stack->next->nb == tab[i + 1])
			return (1);
		i++;
	}
	return (0);
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
// int j = 0;
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

	ft_lstclear(&stack);
	ft_lstclear(&tmp);
}