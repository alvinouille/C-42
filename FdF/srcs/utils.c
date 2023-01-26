/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 08:15:38 by alvina            #+#    #+#             */
/*   Updated: 2023/01/26 18:21:16 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * length + 1);
	if (!str)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	if (s1)
    {
        while (s1[j])
		    str[i++] = s1[j++];
    }
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
    if (s1)
        free(s1);
    if (s2)
        	free(s2);
	return (str);
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

int	ft_atoi(char *nptr)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr[i])
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}

int ft_strlen_modif(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            res++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
        }
        i++;
    }
    return (res);
}

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