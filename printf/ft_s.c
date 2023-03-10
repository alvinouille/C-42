/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:47:28 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:04:47 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *s, char c)
{
	if (s == NULL && c != '\n')
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	return (0);
}
