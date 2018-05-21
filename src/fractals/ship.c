/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 10:56:34 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 18:19:05 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		ft_ship(t_mlx *holder, t_thread *threads_arr, int i, double pr)
{
	double pi;
	double new_re;
	double new_im;
	double old_re;

	while (++YY < threads_arr->counter)
	{
		XX = 0;
		while (XX++ < holder->width)
		{
			pr = 1.5 * (XX - (W >> 1)) / (0.5 * ZOOM * W) + X + MOVEX - 0.5;
			pi = (YY - (H >> 1)) / (0.5 * ZOOM * H) - Y + MOVEY - 0.5;
			new_re = 0;
			new_im = 0;
			i = -1;
			while (++i < ITERATIONS && (new_re * new_re + new_im * new_im) <= 4)
			{
				old_re = new_re;
				new_re = ft_fabs(old_re * old_re - new_im * new_im + pr);
				new_im = ft_fabs((old_re + old_re) * new_im + pi);
				MAGNITUDE = new_re * new_re + new_im * new_im;
			}
			put_colour(i, threads_arr, XX, YY);
		}
	}
}
