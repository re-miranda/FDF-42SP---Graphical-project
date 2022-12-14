/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:23:30 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/27 10:33:45 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf \"map_path\"\n"));
	else if (ft_strncmp(".fdf", ft_strrchr(argv[1], '.'), 4))
		return (ft_printf("\"%s\" Is not a valid .fdf file\n", argv[1]));
	mlx = init_mlx(500, 500, "rmiranda | FDF");
	if (!mlx)
		return (0);
	if (get_map(argv[1], mlx))
		return (ft_printf("Erro ao carregar o mapa\n"));
	put_map(mlx);
	init_input(mlx);
	return (1);
}
