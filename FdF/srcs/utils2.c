/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:39:06 by alvina            #+#    #+#             */
/*   Updated: 2023/02/03 17:40:59 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*str;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
		return (freeer(s1, s2), NULL);
	if (s1)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (freeer(s1, s2), str);
}

int	ft_atoi(char *nptr)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr[i])
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}

int	tab_width(char *str, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != '\0')
			nb++;
		i++;
	}
	return (nb);
}
