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

void	*generator_pile(t_list **a_stack, int nb)
{
	t_list		*new;

	new = ft_lstnew(nb);
	if (!new)
		return (NULL);
	ft_lstadd_back(a_stack, new);
	return (a_stack);
}

int	is_sorted(t_list *stack)
{
	int	curr;
	int	prec;

	curr = 0;
	prec = smaller(stack);
	while (stack)
	{
		curr = stack->nb;
		if (prec <= curr)
			prec = curr;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_exit(t_list **stack, t_list **tmp)
{
	ft_lstclear(stack);
	if (tmp)
		ft_lstclear(tmp);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack;
	t_list	*tmp;
	int		size;

	stack = NULL;
	tmp = NULL;
	if (!parsing(ac, av, &stack))
		return (0);
	if (ac == 4)
		three(&stack);
	else if (ac == 6)
		five(&stack, &tmp, ac - 1);
	else
	{
		pre_selection(&stack, &tmp, ft_lstsize(stack));
		size = ft_lstsize(tmp);
		while (size)
		{
			decision_maker(&stack, &tmp);
			size--;
		}
		finisher(&stack);
	}
	ft_exit(&stack, &tmp);
}
