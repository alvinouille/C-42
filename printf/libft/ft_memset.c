/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:18:14 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 15:32:48 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	int c = 50;
	size_t n = 30;

	printf("%s ", (char*)ft_memset("", c, n));
	printf("%s ", (char*)memset("", c, n));
	return (0);
	char tab[100];
	printf("%s\n", ft_memset(tab, 'A', 42));
	printf("%s\n", memset(tab, 'A', 42));
} */