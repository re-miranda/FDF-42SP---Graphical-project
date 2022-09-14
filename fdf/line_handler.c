/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:10:36 by rmiranda          #+#    #+#             */
/*   Updated: 2022/09/14 09:11:07 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	trace_line(int src_axis[2], int *d, int delta[2], int dest_axis[2])
{
	if (src_axis[0] == dest_axis[0])
		return (0);
	if (*d <= 0)
	{
		src_axis[0]++;
		*d = *d + 2 * delta[1];
	}
	else
	{
		src_axis[0]++;
		src_axis[1]++;
		*d = *d + 2 * (delta[1] - delta[0]);
	}
	return (1);
}

void	draw_line(int src_axis[2], int dest_axis[2], t_mlx_window *window)
{
	int	delta[2];
	int	d;
	int color;

	delta[0] = ft_abs(dest_axis[0] - src_axis[0]);
	delta[1] = ft_abs(dest_axis[1] - src_axis[1]);
	d = 2 * (delta[1] + delta[0]);
	color = rgb_to_int(0, 53, 53);
	pixel_to_image(window, color, src_axis[0], src_axis[1]);
	if (delta[0] >= delta[1])
		while (trace_line(src_axis, &d, delta, dest_axis))
			pixel_to_image(window, color, src_axis[0], src_axis[1]);
	mlx_put_image_to_window (window->ptr, window->window, window->image->ptr, 0, 0);
}
