/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:19:48 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/22 07:21:35 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	*get_next_node(t_mlx *window)
{
	static int	i;
	static int	j;

	if (i >= window->map_size_x)
	{
		i = 0;
		j++;
	}
	if (j >= window->map_size_y)
	{
		j = 0;
		return (NULL);
	}
	return (&window->map[j][i++]);
}

void	linear_translate(int x, int y, t_mlx *window)
{
	t_map	*node_addr;

	node_addr = get_next_node(window);
	while (node_addr)
	{
		node_addr->x += x;
		node_addr->y += y;
		node_addr = get_next_node(window);
	}
	space(window);
}

void	exponential_multiply(int x, int y, t_mlx *window)
{
	t_map	*node_addr;

	node_addr = get_next_node(window);
	while (node_addr)
	{
		node_addr->x *= x;
		node_addr->y *= y;
		node_addr = get_next_node(window);
	}
}
