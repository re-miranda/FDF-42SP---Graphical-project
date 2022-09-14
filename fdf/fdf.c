/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:23:30 by rmiranda          #+#    #+#             */
/*   Updated: 2022/09/14 05:41:34 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_mlx_window	*window;

	window = init_window(640, 360, "rmiranda | FDF");
	if (!window)
		return (0);
	window->image = init_image(window);
	if (!window->image)
	{
		mlx_destroy_window(window->ptr, window->window);
		mlx_destroy_display (window->ptr);
		free(window->ptr);
		free(window);
		return (0);
	}
	init_input(window);
	return (0);
}
