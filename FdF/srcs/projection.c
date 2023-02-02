/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:32:21 by alvina            #+#    #+#             */
/*   Updated: 2023/02/02 17:30:13 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_needle	projection(t_point curr, t_vars *vars)
{
	t_needle	point;

	point.x = (curr.x - curr.y) * (sqrt(2.0) / 2);
	point.y = -(curr.z * (sqrt(2.0 / 3.0)))
		- (1 / (sqrt(6.0)) * -((curr.x + curr.y)));
	point.x = round((vars->origine.x + point.x) * vars->echelle);
	point.y = round((vars->origine.y + point.y) * vars->echelle);
	return (point);
}
