/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:09:02 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 10:23:55 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	action_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		escape(mlx);
	if (keycode == XK_space)
		map_centralize(mlx);
	if (keycode == XK_b || keycode == XK_B)
		put_blue_screen(mlx);
	if (keycode == XK_Up)
		map_node_iterate(func_translate_up, mlx);
	if (keycode == XK_Down)
		map_node_iterate(func_translate_down, mlx);
	if (keycode == XK_Left)
		map_node_iterate(func_translate_left, mlx);
	if (keycode == XK_Right)
		map_node_iterate(func_translate_right, mlx);
	if (keycode == XK_x)
		map_node_iterate(func_increase_z, mlx);
	if (keycode == XK_z)
		map_node_iterate(func_decrease_z, mlx);
	if (keycode == XK_i)
		map_node_iterate(func_multiply_up, mlx);
	if (keycode == XK_o)
		map_node_iterate(func_multiply_down, mlx);
	return (0);
}

void	init_input(t_mlx *mlx)
{
	mlx_key_hook (mlx->window, &action_hook, mlx);
	mlx_expose_hook (mlx->window, &put_map, mlx);
	mlx_hook(mlx->window, 17, 0L, &escape, mlx);
	mlx_loop(mlx->ptr);
}
