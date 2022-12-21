/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:31:09 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 15:22:32 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_make_str(char const *s, char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*str;

	length = ft_strlen(s);
	if (len == 0 || (start > length - 1))
		return (ft_calloc(1, 1));
	if (length < (start + len))
		length = length - start;
	else
		length = len;
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	return (ft_make_str(s, str, start, len));
}

#include<stdio.h>
int main()
{
// char *s = ft_substr("0123456789" , 9, 10);
// printf("%s\n", s);
//  	free(s);
printf("%s", ft_substr("tripouille", 100, 1));
// //     printf("%s\n", ft_substr("yo gros", 3, 2));
// //     printf("%s\n", ft_substr("heyyyyyy", 1, 1000000));
// //     printf("%s\n", ft_substr("heyyyyyy", 2, 0));
// //     printf("%s\n", ft_substr("heyyyyyyyyyy", 10, 0));*/
} 
