/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:23:30 by rmiranda          #+#    #+#             */
/*   Updated: 2022/10/20 12:29:53 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_mlx	*window;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf \"map_path\"\n"));
	window = init_mlx(500, 500, "rmiranda | FDF");
	if (!window)
		return (0);
	if (get_map(argv[1], window))
		return (ft_printf("Erro ao carregar o mapa\n"));
	ft_printf("%i\n", window->map_size_x);
	init_input(window);
	return (1);
}
