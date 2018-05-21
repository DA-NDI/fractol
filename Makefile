#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/05/21 19:09:11 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC_FDF =./src/fractol.c \
	./src/math/ft_fabs.c \
	./src//ft_rgb_convert.c \
	./src/draw.c \
	./src/fractals/ship.c \
	./src/colour_maps.c \
	./src/fractals/mandelbrot.c \
	./src/key.c \
	./src/mouse.c \
	./src/fractals/mandelbrot3.c \
	./src/fractals/mandelbrot2.c

OBJECT_FDF = $(SRC_FDF:.c=.o)

FLAGS = -Wall -Wextra

INCLUDES_MLX = -I /usr/local/include

INCLUDES_FR = -I ./includes/

LIBFT = ./src//libft/libftprintf.a

MLX_LIB = -L /usr/local/lib/

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_FDF)
	make -C ./src//libft
	@echo Fractol compiled
	@gcc -o $(NAME) $(FLAGS) $(INCLUDES_MLX) $(INCLUDES_FR) $(OBJECT_FDF) $(LIBFT) \
	$(MLX_LIB) $(FRAMEWORK) -lpthread

%.o: %.c
	gcc -g $(FLAGS) -o $@ -c $<

clean:
		make -C ./src/libft clean
		/bin/rm -f $(OBJECT_FDF)

fclean: clean
		/bin/rm -f ./src/libft/libftprintf.a
		/bin/rm -f $(NAME)

re:		fclean all tags

tags:
		rm -f TAGS
		etags -R *.c *.h
