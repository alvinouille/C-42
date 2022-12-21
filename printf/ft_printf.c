/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:40:40 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:06:08 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			nb;

	va_start(args, (char *)format);
	i = -1;
	nb = 0;
	nb = ft_core(format, i, nb, args);
	va_end(args);
	return (nb);
}
