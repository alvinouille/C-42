/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:51:30 by marvin            #+#    #+#             */
/*   Updated: 2023/01/04 15:51:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct  s_list
{
    int             nb;
    struct s_list   *next;
}   t_list;

            // UTILS


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


        // INSTRUCTIONS


t_list  **ra(t_list **a_head)
{
    // printf("there\n");
    t_list  *last;
    t_list  *second;
    t_list  *head;

    head = *(a_head);
    printf("<<<<<< 2head : %d\n", head->nb);
    if (head && head->next)
    {
        second = head->next;
        // printf("<<<<<< second 1: %d, head : %d\n", second->nb, (*a_head)->nb);
        last = ft_lstlast(head);
        last->next = head;
        a_head = &second;
        head->next = NULL;
        // printf("<<<<<< second2 : %d, head : %d\n", second->nb, (*a_head)->nb);
    }
    return (a_head);
}

t_list   **sa(t_list **a_head)
{
    t_list  *first;
    t_list  *second;
    t_list  *third;

    first = *(a_head);
    if (first && first->next)
    {
        second = first->next;
        third = second->next;
        first->next = third;
        second->next = first;
        a_head = &second;
    }
    return (a_head);
}

// void    sb(t_list **b_head)
// {
//     t_list  *first;
//     t_list  *second;
//     t_list  *third;

//     first = *(b_head);
//     if (first && first->next)
//     {
//         second = first->next;
//         third = second->next;
//         first->next = third;
//         second->next = first;
//         b_head = &second;
//     }
        // return (b_head);
// }

// void    ss(t_list **a_head, t_list **b_head)
// {
//     sa(a_head);
//     sb(b_head);
// }

        //      MAIN

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
    printf("a_head = %d \n", (*a_head)->nb);
    printf("TEST SA\n");
    a_head = sa(a_head);
    print(a_head);
    printf("a_head = %d \n", (*a_head)->nb);
    printf("TEST RA\n");
    a_head = ra(a_head);
    print(a_head);
    printf("a_head = %d \n", (*a_head)->nb);
}