/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:29:45 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/14 15:12:43 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(long n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_making_str(char *str, long nb, int i)
{
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	str = (char *)malloc(sizeof(char) * ft_length(nb) + 1);
	if (!str)
		return (NULL);
	i = ft_length(nb) - 1;
	str[ft_length(nb)] = '\0';
	return (ft_making_str(str, nb, i));
}

/*#include <stdio.h>
int main()
{
	printf("res = %s\n", ft_itoa(0));
	printf("res = %s\n", ft_itoa(9));
	printf("res = %s\n", ft_itoa(-9));
	printf("res = %s\n", ft_itoa(-9874));
	printf("res = %s\n", ft_itoa(-10));
	printf("res = %s\n", ft_itoa(8124));
	printf("res = %s\n", ft_itoa(-9874));
	printf("res = %s\n", ft_itoa(543000));
	printf("res = %s\n", ft_itoa(-2147483648LL));
	printf("res = %s\n", ft_itoa(2147483647));
} */