/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:39 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 12:40:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	line_down(int i, t_map **map, t_mlx *window)
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	x0 = map[0][i].x;
	x1 = map[0][i].y;
	y0 = map[1][i].x;
	y1 = map[1][i].y;
	ft_printf("[%i:%i-%i:%i]", x0, y0, x1, y1);
	bresenham(x0, y0, x1, y1, window);
}

static void	line_right(int i, t_map **map, t_mlx *window)
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	x0 = map[0][i].x;
	x1 = map[0][i].y;
	y0 = map[0][i + 1].x;
	y1 = map[0][i + 1].y;
	bresenham(x0, y0, x1, y1, window);
}

// void transform_map(t_mlx window)
// {
// 	while ()
// }

void	draw_map(t_mlx *window)
{
	int	i;
	int	j;

	j = 0;
	while (j < (window->map_size_y - 2))
	{
		i = 0;
		while (i < (window->map_size_x - 2))
		{
			// ft_printf("%d\n", window->map_size_x);
			// if (window->map[j][i + 1])
			line_right(i, (window->map + j), window);
			// if (window->map + 1 + j)
			line_down(i, (window->map + j), window);
			i++;
		}
		j++;
	}
}