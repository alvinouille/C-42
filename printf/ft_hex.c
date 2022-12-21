/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:07:00 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:05:20 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long int nb, char c)
{
	int					i;
	char				*strmin;
	char				*strmaj;		

	i = 0;
	strmin = "0123456789abcdef";
	strmaj = "0123456789ABCDEF";
	if (nb >= 16)
	{
		i += ft_hex(nb / 16, c);
		i += ft_hex(nb % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_putchar_fd(strmin[nb], 1);
		else
			ft_putchar_fd(strmaj[nb], 1);
		i++;
	}
	return (i);
}
