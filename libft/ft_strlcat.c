/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:24:21 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 17:58:23 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	sizedest;
	size_t	sizesrc;

	i = 0;
	sizesrc = ft_strlen(src);
	sizedest = ft_strlen(dest);
	if (sizedest >= size)
		return (size + sizesrc);
	if (size == 0)
		return (sizesrc);
	while (src[i] && (i < (size - sizedest -1)))
	{
		dest[sizedest + i] = src[i];
		i++;
	}
	dest[sizedest + i] = '\0';
	return (sizedest + sizesrc);
}
