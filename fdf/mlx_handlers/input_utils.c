/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:09:02 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/18 07:48:59 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	action_hook(int keycode, t_mlx *window)
{
	if (keycode == XK_space)
		space(window);
	if (keycode == XK_Escape)
		escape(window);
    if (keycode == XK_b || keycode == XK_B)
		blue(window);
	return (0);
}

void    init_input(t_mlx *window)
{
    mlx_key_hook (window->window, &action_hook, window);
	mlx_loop(window->ptr);
}