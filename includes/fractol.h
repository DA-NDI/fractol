/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:57:13 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 18:57:35 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define PI 3.1415926
# define RAD 0.017453
# define THREADS_MAX 4
# define ITERATIONS holder->max_iterations
# define INIT holder->init
# define W holder->width
# define H holder->height
# define MOVEX holder->move_x
# define MOVEY holder->move_y
# define ZOOM holder->zoom
# define CREAL holder->c_real
# define CIM holder->c_imaginary
# define XX threads_arr->startx
# define YY threads_arr->starty - 1
# define ADD holder->colour_add
# define X holder->x
# define Y holder->y
# define MAGNITUDE threads_arr->magnitude
# define P 35
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 27
# define PLUS 24
# define NUMPLUS 69
# define NUMMINUS 78
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define LEFTCLICK 1
# define RIGHTCLICK 2
# define WHEELUP 4
# define WHEELDOWN 5
# define LEFTBRACKET 33
# define RIGHTBRACKET 30
# define ENTER 36
# define ESC 53

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include "../src/libft/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct		s_mlx
{
	void			*window;
	void			*init;
	void			*image;
	char			*buff;
	int				colour;
	int				width;
	int				height;
	double			zoom;
	int				size_line;
	double			move_x;
	double			c_real;
	double			c_imaginary;
	double			move_y;
	double			x;
	double			y;
	int				endian;
	void			*img_new;
	int				bpp;
	char			*img_addr;
	double			max;
	int				colour_add;
	int				type;
	int				avto;
	int				max_iterations;
	int				counter;
	int				colour_map;
}					t_mlx;

typedef struct		s_thread
{
	int				startx;
	int				starty;
	double			magnitude;
	int				counter;
	t_mlx			*holder;
}					t_thread;

double				ft_fabs(double nbr);
unsigned int		rgb_conv(unsigned char c1, unsigned char c2, \
						unsigned char c3);
int					ft_draw(t_mlx *holder);
void				ft_mandelbrot(t_mlx *holder, t_thread *threads_arr, int i);
void				ft_mandelbrot3(t_mlx *holder, t_thread *threads_arr, int i);
void				ft_mandelbrot2(t_mlx *holder, t_thread *threads_arr, int i);
void				ft_ship(t_mlx *holder, t_thread *threads_arr\
						, int i, double pr);
void				ft_init_image(t_mlx *holder);
t_mlx				*holder_init(void);
void				put_colour(int i, t_thread *threads_arr, int x, int y);
int					deal_key(int key, t_mlx *holder);
int					mouse_hook(int mouse_key, int x, int y, t_mlx *holder);
int					mouse_move(int x, int y, t_mlx *holder);

#endif
