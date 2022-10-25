/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:19:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 02:28:36 by rmiranda         ###   ########.fr       */
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

void	linear_translate(int x, int y, t_mlx *mlx)
{
	t_map	*node_addr;

	node_addr = get_next_node(mlx);
	while (node_addr)
	{
		node_addr->x += x;
		node_addr->y += y;
		node_addr = get_next_node(mlx);
	}
	put_map(mlx);
}

void	exponential_multiply(int x, int y, t_mlx *mlx)
{
	t_map	*node_addr;

	node_addr = get_next_node(mlx);
	while (node_addr)
	{
		node_addr->x *= x;
		node_addr->y *= y;
		node_addr = get_next_node(mlx);
	}
}
