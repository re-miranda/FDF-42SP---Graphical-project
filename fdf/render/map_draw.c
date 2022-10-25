/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:39 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 02:28:17 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	line_down(int i, int j, t_mlx *mlx)
{
	int	endian;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	endian = j + 1 - mlx->map_size_y;
	if (!endian)
		return ;
	x0 = mlx->map[j][i].x;
	y0 = mlx->map[j][i].y;
	x1 = mlx->map[j + 1][i].x;
	y1 = mlx->map[j + 1][i].y;
	bresenham(x0, y0, x1, y1, mlx);
}

static void	line_right(int i, int j, t_mlx *mlx)
{
	int	endian;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	endian = i + 1 - mlx->map_size_x;
	if (!endian)
		return ;
	x0 = mlx->map[j][i].x;
	y0 = mlx->map[j][i].y;
	x1 = mlx->map[j][i + 1].x;
	y1 = mlx->map[j][i + 1].y;
	bresenham(x0, y0, x1, y1, mlx);
}

void	draw_map(t_mlx *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (j < mlx->map_size_y)
	{
		i = 0;
		while (i < mlx->map_size_x)
		{
			line_right(i, j, mlx);
			line_down(i, j, mlx);
			i++;
		}
		j++;
	}
}
