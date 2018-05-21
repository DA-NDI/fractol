/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:03:39 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 18:48:50 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"
#define I holder->max_iterations
#define M threads_arr->magnitude
#define OLD old_re
#define NEW new_im

static void	ft_mandelbrot_start(t_mlx *holder, t_thread *threads_arr, int i, \
								double pr)
{
	double	pi;
	double	new_re;
	double	new_im;
	double	old_re;

	while (++YY < threads_arr->counter)
	{
		XX = 0;
		while (XX++ < holder->width)
		{
			pr = 1.5 * (XX - (W >> 1)) / (0.5 * ZOOM * W) + X + MOVEX;
			pi = (YY - (H >> 1)) / (0.5 * ZOOM * H) - Y + MOVEY;
			new_re = 0;
			new_im = 0;
			i = -1;
			while (++i < I && (M = new_re * new_re + new_im * new_im) <= 4)
			{
				old_re = new_re;
				new_re = OLD * OLD * OLD - 3 * OLD * new_im * new_im + pr;
				NEW = (3 * OLD * OLD) * NEW - NEW * NEW * NEW + pi;
			}
			put_colour(i, threads_arr, XX, YY);
		}
	}
}

void		ft_mandelbrot3(t_mlx *holder, t_thread *threads_arr, int i)
{
	ft_mandelbrot_start(holder, threads_arr, i, 0);
}
