/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:26:16 by alvina            #+#    #+#             */
/*   Updated: 2023/02/04 19:36:36 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fonction(int signum)
{
	printf("SURPRISE CA QUITTE PAS\n");
}

void	ft_test(int signum, siginfo_t *client, void *str)
{
	printf("OK");
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;
	struct sigaction	test;
	// struct siginfo_t	info;	

	test.sa_sigaction = ft_test;
	sa.sa_handler = fonction;
	pid = getpid();
	printf("PID : %d\n", pid);
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		pause();
	}
	sigaction(SIGUSR1, &test, NULL);
}