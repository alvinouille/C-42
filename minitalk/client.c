/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:05:31 by alvina            #+#    #+#             */
/*   Updated: 2023/02/08 19:36:33 by ale-sain         ###   ########.fr       */
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
	while (octet[j])
	{
		if (octet[size -j] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_msg_received)
			pause();
		write(1, &octet[size - j], 1);
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
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	char				*str;
	char				*octet;
	struct sigaction	sa;

	pid = ft_atoi(av[1]);
	str = av[2];
	i = 0;
	sa.sa_sigaction = &test;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (str[i])
	{
		octet = binaire(str[i]);
		char_sender(octet, pid);
		i++;
	}
	char_sender(binaire('\n'), pid);
	char_sender(binaire('\0'), pid);
}