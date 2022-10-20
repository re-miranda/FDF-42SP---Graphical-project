/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:10:36 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 09:46:03 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham(int x0, int y0, int x1, int y1, t_mlx *window)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	adx;
	int	ady;
	int	sx;
	int	sy;
	int	eps;

	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;
	adx = ft_abs(dx);
	ady = ft_abs(dy);
	sx = -1;
	if (dx > 0)
		sx = 1;
	sy = -1;
	if (dy > 0)
		sy = 1;
	eps = 0;
	if (adx > ady)
	{
		if (dx < 0)
		{
			while (x >= x1)
			{
				mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
				pixel_to_image(window, window->color, x, y);
				eps += ady;
				if (eps << 1 >= adx)
				{
					y += sy;
					eps -= adx;
				}
				x += sx;
			}
		} else
		{
			while (x <= x1)
			{
				mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
				pixel_to_image(window, window->color, x, y);
				eps += ady;
				if (eps << 1 >= adx)
				{
					y += sy;
					eps -= adx;
				}
				x += sx;
			}
		}
	} else
	{
		if (dy < 0)
		{
			while (y >= y1)
			{
				mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
				pixel_to_image(window, window->color, x, y);
				eps += adx;
				if (eps << 1 >= ady) {
					x += sx;
					eps -= ady;
				}
				y += sy;
			}
		} else
		{
			while (y <= y1)
			{
				mlx_put_image_to_window (window->ptr, window->window, window->img->ptr, 0, 0);
				pixel_to_image(window, window->color, x, y);
				eps += adx;
				if (eps << 1 >= ady) {
					x += sx;
					eps -= ady;
				}
				y += sy;
			}
		}
	}
	return ;
}