/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlegrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:41:28 by nlegrand          #+#    #+#             */
/*   Updated: 2022/12/11 01:29:37 by nlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Unimportant function
int	main(int ac, char **av)
{
	t_fdf	fdf;

	errno = 0;
	fdf_setup(&fdf, ac, av);
	set_hooks(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
