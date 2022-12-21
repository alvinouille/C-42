/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:24:58 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 18:10:48 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	i = 0;
	dstlen = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen])
		dstlen++;
	if (size == 0)
		return (srclen);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
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
//     printf("Taille : %ld caracteres\n", ft_strlcpy(NULL, NULL, 0));
//     printf("s1 = %s,\n", dest);
//     // printf("Taille : %ld caracteres\n", strlcpy(NULL, NULL, 0));
//     // printf("s1 = %s\n", dest);
//     //printf("Taille : %ld caracteres\n", strlcpy(s2, s1, 6));
//     //printf("s1 = %s, s2 = %s\n", s1, s2);
//     return (0);
// } 