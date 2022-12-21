/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:35:13 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 14:40:30 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		else
		{
			str++;
			i++;
		}
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int main()
{
	int a = 0;
	printf("%p\n", (ft_memchr("lolpi", a, 1000)));
	printf("%p\n", (memchr("lolpi", a, 1000)));
} */