/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:50:37 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 17:50:38 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*body;

	if (!lst || !(*del) || !(*lst))
		return ;
	head = (*lst);
	while (head)
	{
		body = head->next;
		ft_lstdelone(head, (*del));
		head = body;
	}
	(*lst) = NULL;
}
