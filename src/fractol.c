/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:33:41 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/21 19:50:25 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#define INIT holder->init
#define W holder->width
#define H holder->height
#define MOVEX holder->move_x
#define MOVEY holder->move_y
#define ZOOM holder->zoom

static int	check_type(char *str)
{
	if (!ft_strncmp(str, "Julia", 5))
		return (1);
	else if (!ft_strncmp(str, "Mandelbrot", 10))
		return (2);
	else if (!ft_strncmp(str, "Ship", 4))
		return (3);
	else if (!ft_strncmp(str, "Mandel3", 7))
		return (4);
	else if (!ft_strncmp(str, "Mandel2", 7))
		return (5);
	else
		return (-1);
}

void		ft_init_image(t_mlx *holder)
{
	holder->img_new = mlx_new_image(INIT, holder->width, holder->height);
	holder->img_addr = mlx_get_data_addr(holder->img_new, &(holder->bpp), \
		&(holder->size_line), &(holder->endian));
}

void		ft_print_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

t_mlx		*holder_init(void)
{
	static t_mlx	holder[1];

	holder->height = 600;
	holder->width = 1000;
	holder->x = 0;
	holder->y = 0;
	holder->max = (holder->height * holder->width) << 2;
	holder->zoom = 0.9;
	holder->move_x = 0;
	holder->move_y = 0;
	holder->c_real = 0;
	holder->c_imaginary = 0.7885;
	if (!(holder->init = mlx_init()))
		exit(1);
	holder->window = mlx_new_window(holder->init, W, H, "YO!");
	holder->endian = 0;
	holder->bpp = 8;
	holder->colour_add = 0;
	holder->avto = 0;
	holder->colour_map = 1;
	holder->max_iterations = 50;
	return (holder);
}

int			main(int argc, char **argv)
{
	t_mlx	*holder;
	int		p_id;
	int		a;

	a = 0;
	if (argc < 2 || !argv[1] || argc > 3)
		ft_print_error("\033[0;31m	Usage: ./fractol <argument1> <argument2>\n\
<argument2> is optional. You can use one of the following:\n\
Mandelbrot, Julia, Ship, Mandel3, Mandel2\033[0;0m");
	if (argv[2] && (p_id = fork()) < 0)
		ft_print_error("Couldn't create child process");
	else if (argv[2] && !p_id)
		a = 1;
	holder = holder_init();
	holder->type = check_type(argv[1]);
	if ((holder->type < 0) || (argv[2] && check_type(argv[2]) < 0))
		ft_print_error("Invalid argument/s. Type ./fractol for usage");
	if (a)
		holder->type = check_type(argv[2]);
	ft_draw(holder);
	mlx_hook(holder->window, 6, 1L << 6, mouse_move, holder);
	mlx_hook(holder->window, 2, 5, deal_key, holder);
	mlx_mouse_hook(holder->window, mouse_hook, holder);
	mlx_loop(holder->init);
	return (0);
}
