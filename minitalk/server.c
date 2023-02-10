/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:26:16 by alvina            #+#    #+#             */
/*   Updated: 2023/02/10 17:43:42 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *str;

char	*ft_strjoin(char *s1, char c)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	length = ft_strlen(s1) + 1;
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
	{
		free(s1);
		ft_putstr("Malloc failed\n");
		return (NULL);
	}
	if (s1)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	str[i++] = c;
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

int	print_char(char octet[9])
{
	int c;
	int	i;
	int size;

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

void	ft_exit(char *str)
{
	if (ft_strnstr(str, "exit", 4))
	{
		free(str);
		exit(EXIT_SUCCESS);
	}
}
void	char_receiver(int signum, siginfo_t *client, void *context)
{
	int			pid;
	(void)		context;
	static int i;
	int letter;
	static char octet[9];

	pid = client->si_pid;
	if (signum == SIGUSR1)
	{
		octet[i] = '0';
		i++;
	}
	else if (signum == SIGUSR2)
	{
		octet[i] = '1';
		i++;
	}
	if (kill(pid, SIGUSR1) == -1)
	{
		kill(pid, SIGUSR2);
		free(str);
		exit(EXIT_FAILURE);
	}
	if (i == 8)
	{
		i = 0;
		octet[8] = '\0';
		letter = print_char(octet);
		str = ft_strjoin(str, letter);
		if (!str)
			exit(EXIT_FAILURE);
		if (letter == 0)
		{
			ft_putstr(str);
			ft_exit(str);
			free(str);
			str = 0;
		}
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;
	(void)ac;
	(void)av;

	sa.sa_sigaction = &char_receiver;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		pause();
	}
}