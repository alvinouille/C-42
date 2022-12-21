/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:29:49 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 14:39:32 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;
	int	occ;

	pos = 0;
	i = 0;
	occ = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			pos = i;
			occ = 1;
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	else if (pos != 0 || (pos == 0 && occ == 1))
		return ((char *)&s[pos]);
	else
		return (0);
}

/*#include <stdio.h>
int main()
{
	printf("%s\n", ft_strrchr("bonjour", 'b'));
}*/
