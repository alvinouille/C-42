/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:26:16 by alvina            #+#    #+#             */
/*   Updated: 2023/02/06 18:12:05 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	test(int signum, siginfo_t *client, void *context)
{
	int	pid;
	(void)context;

	pid = client->si_pid;
	printf(".");
	if (signum == SIGUSR1)
		printf("0");
	if (signum == SIGUSR2)
		printf("1");
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &test;
	pid = getpid();
	printf("PID : %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}