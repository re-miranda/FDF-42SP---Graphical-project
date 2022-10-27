/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:52:30 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 10:23:03 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_map(t_mlx *mlx)
{
	int	i;

	i = mlx->map_size_y;
	while (i--)
		free(mlx->map[i]);
	free(mlx->map);
}

int	escape(t_mlx *mlx)
{
	mlx_destroy_window (mlx->ptr, mlx->window);
	mlx_destroy_display (mlx->ptr);
	if (mlx->ptr)
		free(mlx->ptr);
	free_map(mlx);
	if (mlx)
		free(mlx);
	exit (0);
}
