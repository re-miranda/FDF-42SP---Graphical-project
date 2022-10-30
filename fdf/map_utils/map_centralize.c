/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_centralize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:42:34 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/26 11:15:22 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	get_offset(int offset_xy[2], t_mlx *mlx)
{
	int	xy_0[2];
	int	xy_1[2];
	int	xy_middle[2];
	int	screen_middle[2];

	xy_0[0] = mlx->map[0][0].x;
	xy_0[1] = mlx->map[0][0].y;
	xy_1[0] = mlx->map[mlx->map_size_y - 1][mlx->map_size_x - 1].x;
	xy_1[1] = mlx->map[mlx->map_size_y - 1][mlx->map_size_x - 1].y;
	xy_middle[0] = (xy_0[0] + xy_1[0]) / 2;
	xy_middle[1] = (xy_0[1] + xy_1[1]) / 2;
	screen_middle[0] = mlx->size_x / 2;
	screen_middle[1] = mlx->size_y / 2;
	offset_xy[0] = screen_middle[0] - xy_middle[0];
	offset_xy[1] = screen_middle[1] - xy_middle[1];
	return ;
}

void	map_centralize(t_mlx *mlx)
{
	t_map	*node_addr;
	int		offset_xy[2];

	get_offset(offset_xy, mlx);
	node_addr = get_next_node(mlx);
	while (node_addr)
	{
		node_addr->x += offset_xy[0];
		node_addr->y += offset_xy[1];
		node_addr = get_next_node(mlx);
	}
	put_map(mlx);
}
