/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:26:53 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 15:26:00 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size > 0 && (nmemb > ((size_t)- 1 / size)))
		return (NULL);
	tab = (char *)malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (size * nmemb));
	return (tab);
}
