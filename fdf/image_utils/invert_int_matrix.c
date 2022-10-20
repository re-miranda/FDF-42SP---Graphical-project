/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_int_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:35:56 by rmiranda          #+#    #+#             */
/*   Updated: 2022/09/17 12:18:53 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void x_invert_int_matrix(int *matrix, int width, int height)
{
    int *line;
    int    x;
    int    y;

    y = 0;
    line = matrix;
    while (y < height)
    {
        x = 0;
        while (x < width / 2)
        {
            int_swap(&line[x], &line[width - x]);
            x++;
        }
        line += width;
        y++;
    }
}

void y_invert_int_matrix(int *matrix, int width, int height)
{
    int *line;
    int    x;
    int    y;

    y = height;
    line = matrix;
    while (y)
    {
        x = 0;
        while (x < width)
        {
            int_swap(&line[x], &line[x + (width * (y - 1))]);
            x++;
        }
        line += width;
        y -= 2;
    }
}
