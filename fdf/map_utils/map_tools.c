/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:19:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 10:31:50 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_map	*get_next_node(t_mlx *mlx)
{
	static int	i;
	static int	j;

	if (i >= mlx->map_size_x)
	{
		i = 0;
		j++;
	}
	if (j >= mlx->map_size_y)
	{
		j = 0;
		return (NULL);
	}
	return (&mlx->map[j][i++]);
}

void	map_node_iterate(void (*f)(t_map *, t_mlx *), t_mlx *mlx)
{
	t_map	*node_addr;

	node_addr = get_next_node(mlx);
	while (node_addr)
	{
		
		f(node_addr, mlx);
		node_addr = get_next_node(mlx);
	}
	put_map(mlx);
}

void	isometric_projection(int tile_width, int tile_height, t_mlx *mlx)
{
	t_map	*node_addr;
	int	x;
	int	y;
	int	offset_x;
	int	offset_y;

	node_addr = get_next_node(mlx);
	offset_x = ft_abs(mlx->size_x - tile_width * mlx->map_size_x) / 2;
	offset_y = ft_abs(mlx->size_y - tile_height * mlx->map_size_y) / 2;
	while (node_addr)
	{
		x = node_addr->x;
		y = node_addr->y;
		node_addr->x = (x - y) * tile_width / 2;
		node_addr->y = (x + y) * tile_height / 2;
		node_addr->x += offset_x;
		node_addr->y += offset_y;
		node_addr = get_next_node(mlx);
	}
}
