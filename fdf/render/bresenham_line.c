/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:10:36 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 02:21:40 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	low_slope(t_bresen *line, t_mlx *mlx)
{
	int	decisive;
	int	ppl;

	decisive = 0;
	ppl = 0;
	pixel_to_image(mlx, mlx->color, line->x0, line->y0);
	decisive = (2 * line->dy) - line->dx;
	while (ppl < line->dx)
	{
		ppl++;
		line->x0 += line->sx;
		if (decisive < 0)
			decisive += (2 * line->dy);
		else
		{
			line->y0 += line->sy;
			decisive += ((2 * line->dy) - (2 * line->dx));
		}
		pixel_to_image(mlx, mlx->color, line->x0, line->y0);
	}
}

static void	high_slope(t_bresen *line, t_mlx *mlx)
{
	int	decisive;
	int	ppl;

	decisive = 0;
	ppl = 0;
	pixel_to_image(mlx, mlx->color, line->x0, line->y0);
	decisive = (2 * line->dx) - line->dy;
	while (ppl < line->dy)
	{
		ppl++;
		line->y0 += line->sy;
		if (decisive < 0)
			decisive += (2 * line->dx);
		else
		{
			line->x0 += line->sx;
			decisive += ((2 * line->dx) - (2 * line->dy));
		}
		pixel_to_image(mlx, mlx->color, line->x0, line->y0);
	}
}

void	bresenham(t_bresen *line, t_mlx *mlx)
{
	line->dx = (line->x1 - line->x0);
	if (line->dx > 0)
		line->sx = 1;
	else
		line->sx = -1;
	line->dx = abs(line->dx);
	line->dy = (line->y1 - line->y0);
	if (line->dy > 0)
		line->sy = 1;
	else
		line->sy = -1;
	line->dy = abs(line->dy);
	if (line->dx > line->dy)
		low_slope(line, mlx);
	else
		high_slope(line, mlx);
}
