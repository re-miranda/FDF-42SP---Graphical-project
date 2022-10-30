/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:14:54 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/28 09:22:16 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>

static char	*open_map(char *path)
{
	int		fd;
	char	*map;

	fd = open(path, O_RDONLY);
	if (!fd)
		return (NULL);
	map = get_whole_file(fd);
	close(fd);
	return (map);
}

int	get_map(char *path, t_mlx *mlx)
{
	char	*file_contents;

	file_contents = open_map(path);
	if (!file_contents)
		return (1);
	load_map(file_contents, mlx);
	free(file_contents);
	if (!mlx->map)
		return (3);
	isometric_projection(mlx);
	return (0);
}
