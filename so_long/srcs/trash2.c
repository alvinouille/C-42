/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:09 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/02 12:38:18 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_gnl(char *str, int flag)
{
	if (!str)
	{
		ft_putstr_fd("Error\nEmpty map or repository !\n", 2);
		exit(1);
	}
	if (flag == 1)
	{
		free(str);
		ft_putstr_fd("Error\nInvalid map !\n", 2);
		exit(1);
	}
}
