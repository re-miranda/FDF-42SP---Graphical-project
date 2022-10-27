/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:39 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 02:20:05 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	line_down(int i, int j, t_mlx *mlx)
{
	int			endian;
	t_bresen	line;

	endian = j + 1 - mlx->map_size_y;
	if (!endian)
		return ;
	line.x0 = mlx->map[j][i].x;
	line.y0 = mlx->map[j][i].y - mlx->map[j][i].z;
	line.x1 = mlx->map[j + 1][i].x;
	line.y1 = mlx->map[j + 1][i].y - mlx->map[j + 1][i].z;
	bresenham(&line, mlx);
}

static void	line_right(int i, int j, t_mlx *mlx)
{
	int			endian;
	t_bresen	line;

	endian = i + 1 - mlx->map_size_x;
	if (!endian)
		return ;
	line.x0 = mlx->map[j][i].x;
	line.y0 = mlx->map[j][i].y - mlx->map[j][i].z;
	line.x1 = mlx->map[j][i + 1].x;
	line.y1 = mlx->map[j][i + 1].y - mlx->map[j][i + 1].z;
	bresenham(&line, mlx);
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
