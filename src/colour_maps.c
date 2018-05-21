/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 21:13:49 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 16:41:08 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#define HOLDER threads_arr->holder

void	map_fractional_count(int i, t_thread *threads_arr, int x, int y)
{
	int		color;
	int		j;

	color = 1000 * (i + 1.0 * ((log(log(21000) - log(log(MAGNITUDE))) /\
		log(2)))) - HOLDER->colour_add;
	j = x * 4 + y * HOLDER->size_line;
	(HOLDER->img_addr)[j] = color;
	(HOLDER->img_addr)[++j] = color >> 8;
	(HOLDER->img_addr)[++j] = color >> 16;
}

void	map_linear_count(int i, t_thread *threads_arr, int x, int y)
{
	int		color;
	int		j;

	color = i * 16 - HOLDER->colour_add;
	j = x * 4 + y * HOLDER->size_line;
	(HOLDER->img_addr)[j] = color;
	(HOLDER->img_addr)[++j] = color >> 8;
	(HOLDER->img_addr)[++j] = color >> 16;
}

void	map_putcolour_s(int i, t_thread *threads_arr, int x, int y)
{
	int		j;

	j = x * 4 + y * HOLDER->size_line;
	(HOLDER->img_addr)[j] = sin(0.1 * i + 0) * 127 + 128;
	(HOLDER->img_addr)[++j] = sin(0.1 * i + 2) * 127 + 128;
	(HOLDER->img_addr)[++j] = sin(0.1 * i + 4) * 127 + 128;
}

void	put_colour(int i, t_thread *threads_arr, int x, int y)
{
	if (HOLDER->colour_map == 1)
		map_fractional_count(i, threads_arr, x, y);
	else if (HOLDER->colour_map == 2)
		map_linear_count(i, threads_arr, x, y);
	else if (HOLDER->colour_map == 3)
		map_putcolour_s(i, threads_arr, x, y);
}
