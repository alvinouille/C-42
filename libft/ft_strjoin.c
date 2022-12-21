/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:23:45 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 15:03:22 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	printf("%s", ft_strjoin(av[1], av[2]));
}  */