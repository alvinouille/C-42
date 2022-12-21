/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:17:15 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 18:10:25 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst;

	dst = (char *)dest;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*(dst++) = *(char *)(src++);
		n--;
	}
	return (dest);
}

// #include <stdlib.h>
// #include <bsd/string.h>
// #include<string.h>
// #include <stdio.h>
// int main()
// {
//     /*char s1[50] = "yo mon pote";
//     char s2[1] = "";
//     printf("Taille : %ld caracteres\n", ft_strlcpy(s2, s1, 6));
//     printf("s1 = %s, s2 = %s\n", s1, s2);*/
//     char src[] = "coucou";
//     char dest[10]; memset(dest, 'A', 10);
//     //printf("%s", ft_memcpy(dest, NULL, 10));
//     // printf("%s", memcpy(NULL, NULL, 10));
//     //printf("Taille : %ld caracteres\n", strlcpy(s2, s1, 6));
//     //printf("s1 = %s, s2 = %s\n", s1, s2);
//     return (0);
// } 
