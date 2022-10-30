/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:52:30 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/28 12:46:26 by rmiranda         ###   ########.fr       */
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
	if (mlx->map)
		free_map(mlx);
	if (mlx)
		free(mlx);
	exit (0);
}

void	abort_load(char *file_contents, char **split, t_mlx *mlx)
{
	int	i;

	i = 0;
	free(file_contents);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	ft_printf("Loading aborted due to inconsistent line in the file.\n");
	escape(mlx);
}
