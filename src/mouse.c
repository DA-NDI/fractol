/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:33:41 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 17:51:51 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_move(int x, int y, t_mlx *holder)
{
	if (x < 0 || y < 0 || x > holder->width || y > holder->height)
		return (0);
	x -= W / 2;
	y -= H / 2;
	holder->c_real = (1.0 * x / W) * 2;
	holder->c_imaginary = (1.0 * y / H) * 2;
	ft_draw(holder);
	return (0);
}

int		mouse_hook(int mouse_key, int x, int y, t_mlx *holder)
{
	x -= W / 2;
	y -= H / 2;
	if (mouse_key == WHEELUP || mouse_key == LEFTCLICK)
	{
		holder->zoom *= 1.2;
		holder->colour_add += mouse_key * 50;
		holder->x += x / holder->zoom / W;
		holder->y -= y / holder->zoom / H;
	}
	else if (mouse_key == WHEELDOWN || mouse_key == RIGHTCLICK)
	{
		holder->colour_add -= mouse_key * 50;
		holder->zoom /= 1.2;
	}
	ft_draw(holder);
	return (0);
}
