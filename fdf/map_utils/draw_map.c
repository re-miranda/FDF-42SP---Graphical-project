/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:39 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/21 09:04:33 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	line_down(int i, int j, t_mlx *window)
{
	int	endian;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	endian = j + 1 - window->map_size_y;
	if (!endian)
		return ;
	x0 = window->map[j][i].x;
	y0 = window->map[j][i].y;
	x1 = window->map[j + 1][i].x;
	y1 = window->map[j + 1][i].y;
	bresenham(x0, y0, x1, y1, window);
}

static void	line_right(int i, int j, t_mlx *window)
{
	int	endian;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	endian = i + 1 - window->map_size_x;
	if (!endian)
		return ;
	x0 = window->map[j][i].x;
	y0 = window->map[j][i].y;
	x1 = window->map[j][i + 1].x;
	y1 = window->map[j][i + 1].y;
	bresenham(x0, y0, x1, y1, window);
}

void	draw_map(t_mlx *window)
{
	int	i;
	int	j;

	j = 0;
	while (j < window->map_size_y)
	{
		i = 0;
		while (i < window->map_size_x)
		{
			line_right(i, j, window);
			line_down(i, j, window);
			i++;
		}
		j++;
	}
}