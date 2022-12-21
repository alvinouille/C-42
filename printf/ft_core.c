/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:41:35 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:05:30 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_modif(int a)
{
	ft_putchar_fd(a, 1);
	return (1);
}

int	ft_core(const char *format, int i, int nb, va_list args)
{	
	while (format[++i])
	{
		if (format[i] != '%')
			nb += ft_putchar_modif((int)(format[i]));
		else
		{
			if (format[++i] && (format[i] == 'd' || format[i] == 'i'
					|| format[i] == 'c'))
				nb += ft_d_i_c(va_arg(args, int), format[i]);
			if (format[i] == '%')
				nb += ft_percent();
			if (format[i] == 's')
				nb += ft_s(va_arg(args, char *), format[i + 1]);
			if (format[i] == 'p')
				nb += ft_p(va_arg(args, void *));
			if (format[i] == 'u')
				nb += ft_putnbr_un(va_arg(args, unsigned int));
			if (format[i] == 'x' || format[i] == 'X')
				nb += ft_hex(va_arg(args, unsigned int), format[i]);
		}
	}
	return (nb);
}
