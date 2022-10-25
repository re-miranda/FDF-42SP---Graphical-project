/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 04:02:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 10:40:31 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	func_increase_z(t_map *node_addr, t_mlx *mlx)
{
	node_addr->z *= 1.2;
	(void)mlx;
}

void	func_decrease_z(t_map *node_addr, t_mlx *mlx)
{
	int	z;

	z = node_addr->z * 0.8;
	if (z > 4)
		node_addr->z = z;
	(void)mlx;
}

void	func_translate_up(t_map *node_addr, t_mlx *mlx)
{
	node_addr->y += -10;
	(void)mlx;
}

void	func_translate_down(t_map *node_addr, t_mlx *mlx)
{
	node_addr->y += 10;
	(void)mlx;
}

void	func_translate_right(t_map *node_addr, t_mlx *mlx)
{
	node_addr->x += 10;
	(void)mlx;
}

void	func_translate_left(t_map *node_addr, t_mlx *mlx)
{
	node_addr->x += -10;
	(void)mlx;
}