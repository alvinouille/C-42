/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:33:45 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:05:25 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_modif(int n)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i++;
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		i += ft_putnbr_modif(nb / 10);
		i += ft_putnbr_modif(nb % 10);
	}
	else
	{	
		i++;
		ft_putchar_fd((nb + 48), 1);
	}
	return (i);
}

int	ft_d_i_c(int tmp, char c)
{
	int		nb;

	nb = 0;
	if (c == 'd' || c == 'i')
	{
		nb += ft_putnbr_modif(tmp);
		return (nb);
	}
	else
	{
		ft_putchar_fd(tmp, 1);
		return (1);
	}
}
