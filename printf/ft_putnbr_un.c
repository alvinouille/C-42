/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:58 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:05:09 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int nb)
{
	long unsigned int	n;
	int					i;

	i = 0;
	n = nb;
	if (n == 0)
	{
		i = 1;
		ft_putchar_fd('0', 1);
		return (i);
	}
	if (n >= 10)
	{
		i += ft_putnbr_un(n / 10);
		i += ft_putnbr_un(n % 10);
	}
	else
	{
		i++;
		ft_putchar_fd(n + 48, 1);
	}
	return (i);
}
