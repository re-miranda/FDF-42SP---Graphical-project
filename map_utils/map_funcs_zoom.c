/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs_zoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:17:14 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/26 11:17:34 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	func_multiply_down(t_map *node_addr, t_mlx *mlx)
{
	node_addr->x *= 0.5;
	node_addr->y *= 0.5;
	(void)mlx;
}

void	func_multiply_up(t_map *node_addr, t_mlx *mlx)
{
	node_addr->x *= 2;
	node_addr->y *= 2;
	(void)mlx;
}

void	func_increase_z(t_map *node_addr, t_mlx *mlx)
{
	node_addr->z *= 2;
	(void)mlx;
}

void	func_decrease_z(t_map *node_addr, t_mlx *mlx)
{
	int	z;

	z = node_addr->z / 2;
	if (z > 1)
		node_addr->z = z;
	(void)mlx;
}
