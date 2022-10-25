/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:09:02 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/25 02:31:19 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	action_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		escape(mlx);
	if (keycode == XK_space)
		put_map(mlx);
    if (keycode == XK_b || keycode == XK_B)
		put_blue_screen(mlx);
    if (keycode == XK_Up)
		linear_translate(0, -10, mlx);
    if (keycode == XK_Down)
		linear_translate(0, 10, mlx);
    if (keycode == XK_Left)
		linear_translate(-10, 0, mlx);
    if (keycode == XK_Right)
		linear_translate(10, 0, mlx);
    if (keycode == XK_x)
		exponential_multiply(20, 20, mlx);
	return (0);
}

void    init_input(t_mlx *mlx)
{
    mlx_key_hook (mlx->window, &action_hook, mlx);
	mlx_loop(mlx->ptr);
}