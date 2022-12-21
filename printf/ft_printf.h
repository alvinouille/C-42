/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:32:17 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 18:03:34 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"

int		ft_core(const char *format, int i, int nb, va_list args);
int		ft_putnbr_un(unsigned int nb);
int		ft_hex(unsigned long int nb, char c);
int		ft_d_i_c(int tmp, char c);
int		ft_p(void *ptr);
int		ft_percent(void);
int		ft_s(char *s, char c);
int		ft_printf(const char *format, ...);

#endif