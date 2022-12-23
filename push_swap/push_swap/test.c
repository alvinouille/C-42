int	ft_atoi(const char *nptr)
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

#include <stdio.h>
#include <stdlib.h>
// #include <limits.h>
int main(int ac, char **av)
{
	// char *str = "-9223372036854775809";
	printf("result fr : %d\n", atoi(av[1]));
	printf("your result : %d\n", ft_atoi(av[1]));
	return (0);
}