/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:35:26 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 18:43:13 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	display_menu(t_mlx *holder)
{
	char *free_me;

	free_me = ft_itoa(holder->max_iterations);
	mlx_string_put(holder->init, holder->window, 5, 0, 2000, "---Hey! I'm  \
Menu -------");
	mlx_string_put(holder->init, holder->window, 5, 30, 3000, "*Up          \
	{u} ********");
	mlx_string_put(holder->init, holder->window, 5, 60, 4000, "**Down       \
	{d} ********");
	mlx_string_put(holder->init, holder->window, 5, 90, 5000, "**Left       \
	{l} ********");
	mlx_string_put(holder->init, holder->window, 5, 120, 25000, "**Right      \
	{r} ********");
	mlx_string_put(holder->init, holder->window, 5, 150, 19, "**Zoom + - \
	{=, -}  ******");
	mlx_string_put(holder->init, holder->window, 5, 180, 19, "**Iterations");
	mlx_string_put(holder->init, holder->window, 220, 180, 19, free_me);
	free(free_me);
}

static void	ft_julia(t_mlx *holder, t_thread *threads_arr, int i)
{
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;

	while (++YY < threads_arr->counter)
	{
		XX = 0;
		while (XX++ < holder->width)
		{
			new_re = 1.5 * (XX - W / 2) / (0.5 * ZOOM * W) + holder->x + MOVEX;
			new_im = (YY - H / 2) / (0.5 * ZOOM * H) - holder->y + MOVEY;
			i = -1;
			while (++i < holder->max_iterations)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + CREAL;
				new_im = 2 * old_re * old_im + CIM;
				if ((MAGNITUDE = new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			put_colour(i, threads_arr, XX, YY);
		}
	}
}

static int	ft_divide(void *holder)
{
	t_thread	*tmp;

	tmp = (t_thread *)holder;
	if (tmp->holder->type == 1)
		ft_julia(tmp->holder, tmp, 0);
	else if (tmp->holder->type == 2)
		ft_mandelbrot(tmp->holder, tmp, 0);
	else if (tmp->holder->type == 3)
		ft_ship(tmp->holder, tmp, 0, 0);
	else if (tmp->holder->type == 4)
		ft_mandelbrot3(tmp->holder, tmp, 0);
	else if (tmp->holder->type == 5)
		ft_mandelbrot2(tmp->holder, tmp, 0);
	return (0);
}

int			ft_draw(t_mlx *holder)
{
	int			i;
	int			high;
	pthread_t	thread1[THREADS_MAX];
	t_thread	threads_arr[THREADS_MAX];

	ft_init_image(holder);
	high = holder->height / THREADS_MAX;
	i = -1;
	while (++i < THREADS_MAX)
	{
		threads_arr[i].counter = high * i + high;
		threads_arr[i].starty = high * i;
		threads_arr[i].startx = 0;
		threads_arr[i].holder = holder;
		pthread_create(&thread1[i], NULL, (void*)ft_divide, &threads_arr[i]);
	}
	while (i--)
		pthread_join(thread1[i], NULL);
	mlx_put_image_to_window(INIT, holder->window, holder->img_new, 0, 0);
	mlx_destroy_image(INIT, holder->img_new);
	display_menu(holder);
	return (0);
}
