/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:41:31 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/26 11:11:48 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric_projection(t_mlx *mlx)
{
	t_map	*node_addr;
	int		x;
	int		y;
	int		tile_width;
	int		tile_height;

	node_addr = get_next_node(mlx);
	tile_width = mlx->global_multiplier;
	tile_height = tile_width / 2;
	while (node_addr)
	{
		x = node_addr->x;
		y = node_addr->y;
		node_addr->x = (x - y) * tile_width / 2;
		node_addr->y = (x + y) * tile_height / 2;
		node_addr = get_next_node(mlx);
	}
	map_centralize(mlx);
}
