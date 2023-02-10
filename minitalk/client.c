/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:05:31 by alvina            #+#    #+#             */
/*   Updated: 2023/02/10 17:45:11 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int     g_msg_received;

char	*binaire(char c)
{
	int		i;
	char	*octet;

	i = 0;
	octet = malloc(sizeof(char) * 9);
	if (!octet)
	{
		ft_putstr("Malloc failed\n");
		return (NULL);
	}
	while (i < 8)
	{
		octet[i] = (c % 2) + '0';
		c /= 2;
		i++;
	}
	octet[8] = '\0';
	return (octet);
}

void	char_sender(char *octet, int pid)
{
	int	j;
	int	size;

	j = 0;
	size = 7;
	g_msg_received = 0;
	if (!octet)
		exit(EXIT_FAILURE);
	while (octet[j])
	{
		if (octet[size -j] == '0')
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				free(octet);
				exit(EXIT_FAILURE);
			}

		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				free(octet);
				exit(EXIT_FAILURE);
			}
		}
		while (!g_msg_received)
			pause();
		j++;
		g_msg_received = 0;
	}
	free(octet);
}

void	test(int signum, siginfo_t *client, void *context)
{
	(void)client;
	(void)context;
	if (signum == SIGUSR1)
		g_msg_received = 1;
	if (signum == SIGUSR2)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	char				*str;
	char				*octet;
	struct sigaction	sa;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("Usage : ./client <server PID> <message>\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	sa.sa_sigaction = &test;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (str[i])
	{
		while (str[i])
		{
			octet = binaire(str[i]);
			char_sender(octet, pid);
			i++;
		}
		char_sender(binaire('\n'), pid);
	}
	char_sender(binaire('\0'), pid);
}