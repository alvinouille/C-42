/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:15:38 by alvina            #+#    #+#             */
/*   Updated: 2023/02/01 20:40:53 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		around(float nb)
{
	if (nb - (int)nb > 0.5)
        return ((int)ceil(nb));
    else
		return ((int)floor(nb));
}

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

void	img_pixel_put(t_data *img, double x, double y, int color)
{
	char	*px;

	px = img->addr + around((y * img->line_length + x * (img->bits_per_pixel / 8)));
	
	*(unsigned int*)px = color;
}

// int ft_strlen_modif(char *str)
// {
//     int i;
//     int res;

//     i = 0;
//     res = 0;
//     if (!str)
//         return (0);
//     while (str[i] && str[i] != '\n')
//     {
//         if (str[i] >= '0' && str[i] <= '9')
//         {
//             res++;
//             while (str[i] >= '0' && str[i] <= '9')
//                 i++;
//         }
//         i++;
//     }
//     return (res);
// }

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}
