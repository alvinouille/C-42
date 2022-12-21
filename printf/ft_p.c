/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:53:02 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:03:58 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(void *ptr)
{
	unsigned long int	nb;

	nb = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		nb = (unsigned long int)ptr;
		ft_putstr_fd("0x", 1);
		return (ft_hex(nb, 'x') + 2);
	}
}
