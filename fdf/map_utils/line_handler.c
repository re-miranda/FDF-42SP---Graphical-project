/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:10:36 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/23 10:25:11 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	y_axis_pixel(t_bresen *bresen, t_mlx *window)
{
	// pixel_put(img, bresen->x0, bresen->y0, start->color);
	pixel_to_image(window, window->color, bresen->x0, bresen->y0);
	bresen->eps += bresen->adx;
	if (bresen->eps * 2 >= bresen->ady)
	{
		bresen->x0 += bresen->sx;
		bresen->eps -= bresen->ady;
	}
}

static void	x_axis_pixel(t_bresen *bresen, t_mlx *window)
{
	// pixel_put(img, start->x, start->y, start->color);
	pixel_to_image(window, window->color, bresen->x0, bresen->y0);
	bresen->eps += bresen->ady;
	if (bresen->eps * 2 >= bresen->adx)
	{
		bresen->y0 += bresen->sy;
		bresen->eps -= bresen->adx;
	}
}

static void	y_axis_fast(t_bresen *bresen, t_mlx *window)
{
	if (bresen->sy < 0)
	{
		while (bresen->y0 >= bresen->y1)
		{
			y_axis_pixel(bresen, window);
			bresen->y0 += bresen->sy;
		}
	}
	else
	{
		while (bresen->y0 <= bresen->y1)
		{
			y_axis_pixel(bresen, window);
			bresen->y0 += bresen->sy;
		}
	}
}

static void	x_axis_fast(t_bresen *bresen, t_mlx *window)
{
	if (bresen->sx < 0)
	{
		while (bresen->x0 >= bresen->x1)
		{
			x_axis_pixel(bresen, window);
			bresen->x0 += bresen->sx;
		}
	}
	else
	{
		while (bresen->x0 <= bresen->x1)
		{
			x_axis_pixel(bresen, window);
			bresen->x0 += bresen->sx;
		}
	}
}

void	bresenham(int x0, int y0, int x1, int y1, t_mlx *window)
{
	t_bresen	bresen;

	bresen.x0 = x0;
	bresen.x1 = x1;
	bresen.y0 = y0;
	bresen.y1 = y1;
	bresen.dx = bresen.x1 - bresen.x0;
	bresen.dy = bresen.y1 - bresen.y0;
	bresen.adx = ft_abs(bresen.dx);
	bresen.ady = ft_abs(bresen.dy);
	bresen.sx = -1;
	if (bresen.dx > 0)
		bresen.sx = 1;
	bresen.sy = -1;
	if (bresen.dy > 0)
		bresen.sy = 1;
	bresen.eps = 0;
	if (bresen.adx > bresen.ady)
		x_axis_fast(&bresen, window);
	else
		y_axis_fast(&bresen, window);
}
