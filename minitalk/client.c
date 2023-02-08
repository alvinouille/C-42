/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:05:31 by alvina            #+#    #+#             */
/*   Updated: 2023/02/04 18:26:04 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int main(int ac, char **av)
{
    int     pid;
    // int     i;
    // char    *str;
    // char    *octet;

    pid = ft_atoi(av[1]);
    // str = av[2];
    // i = 0;
    kill(pid, SIGUSR1);
    // while (str[i])
    // {
    //     octet = binaire(str[i]);
    //     while (octet[j])
    //     {
    //         if (octet[j] == 0)
    //             kill(pid, SIGUSR1);
    //     }
    // }
    
}