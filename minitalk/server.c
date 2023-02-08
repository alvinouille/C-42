/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:26:16 by alvina            #+#    #+#             */
/*   Updated: 2023/02/08 19:37:12 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char c)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(s1) + 1;
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	str[i++] = c;
	str[i] = '\0';
	return (str);
}

int	print_char(char octet[9])
{
	int c;
	int	i;
	int size;
	int nb = 0;

	c = 0;
	i = 0;
	size = 7;
	while (octet[i])
	{
		c += ft_recursive_power(2, i) * (octet[size - i] - 48);
		i++;
	}
	return (c);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	char_receiver(int signum, siginfo_t *client, void *context)
{
	int			pid;
	(void)		context;
	static int i;
	static char *str;
	int letter;
	static char octet[9];

	pid = client->si_pid;

	if (signum == SIGUSR1)
		octet[i] = '0';
	else if (signum == SIGUSR2)
		octet[i] = '1';
	kill(pid, SIGUSR1);
	i++;
	if (i == 8)
	{
		i = 0;
		octet[8] = '\0';
		letter = print_char(octet);
		// ft_putchar(letter);
		// ft_putnbr(letter);
		str = ft_strjoin(str, letter);
		if (letter == 0)
		{
			ft_putstr(str);
			free(str);
		}
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &char_receiver;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	ft_putchar('\n');
}