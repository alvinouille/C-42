/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:14 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 15:28:01 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_occ(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_first_occ(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_occ(str[i], set) == 0)
			return (i);
		i++;
	}
	return (0);
}

int	find_end_occ(char const *str, char const *set)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		if (is_occ(str[i], set) == 0)
			return (i + 1);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i_start;
	int		i_end;
	int		length;
	int		i;

	i = 0;
	i_start = find_first_occ(s1, set);
	i_end = find_end_occ(s1, set);
	length = i_end - i_start;
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	while (length - i > 0)
	{
		str[i] = s1[i_start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
int main()
{
	printf("%s\n", ft_strtrim("!!!", "!!!!!!"));
}  */