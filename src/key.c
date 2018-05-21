/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:33:41 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 18:51:13 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	reset_flags(t_mlx *holder)
{
	holder->zoom = 0.9;
	holder->move_x = 0;
	holder->move_y = 0;
	holder->c_real = -0.835;
	holder->c_imaginary = -0.2321;
	holder->colour_add = 0;
	holder->x = 0;
	holder->y = 0;
}

static void	deal_key_2(int key, t_mlx *holder)
{
	if (key == LEFTBRACKET || key == RIGHTBRACKET)
	{
		if (key == RIGHTBRACKET)
			holder->zoom *= 5;
		else
			holder->zoom /= 5;
	}
	else if (key == P)
		reset_flags(holder);
	else if (key == 36)
		holder->avto = 1;
	else if (key == ENTER)
		holder->avto = 0;
	else if (key == ONE || key == TWO || key == THREE || key == FOUR)
	{
		if (key == ONE)
			holder->colour_map = 1;
		else if (key == TWO)
			holder->colour_map = 2;
		else if (key == THREE)
			holder->colour_map = 3;
		else if (key == FOUR)
			holder->colour_add += key * 50;
	}
}

static void	deal_key_move(int key, t_mlx *holder)
{
	if (key == LEFT || key == RIGHT)
	{
		if (key == RIGHT)
			holder->move_x = holder->move_x + 0.12 / holder->zoom;
		else
			holder->move_x = holder->move_x - 0.12 / holder->zoom;
	}
	else if (key == UP || key == DOWN)
	{
		if (key == DOWN)
			holder->move_y = holder->move_y + 0.12 / holder->zoom;
		else
			holder->move_y = holder->move_y - 0.12 / holder->zoom;
	}
}

static void	deal_key_1(int key, t_mlx *holder)
{
	if (key == ESC)
		exit(1);
	else if (key == NUMPLUS || key == NUMMINUS)
	{
		if (key == NUMPLUS)
			holder->max_iterations += 50;
		else
			holder->max_iterations -= 50;
	}
	else if (key == PLUS || key == MINUS)
	{
		if (key == PLUS)
			holder->zoom *= 2;
		else
			holder->zoom /= 2;
	}
	while (holder->avto)
	{
		holder->zoom *= 5;
		ft_draw(holder);
	}
}

int			deal_key(int key, t_mlx *holder)
{
	deal_key_1(key, holder);
	deal_key_2(key, holder);
	deal_key_move(key, holder);
	ft_draw(holder);
	return (0);
}
