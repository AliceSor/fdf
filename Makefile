# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoroka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 18:13:07 by asoroka           #+#    #+#              #
#    Updated: 2017/04/05 17:53:45 by asoroka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -c -Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = fdf.h

SRC = main.c			\
	  lists.c			\
	  create.c			\
	  put_line.c		\
	  put_pixel.c 		\
	  foreachpoint.c 	\
	  fill_down.c 		\
	  zoom.c 			\
	  calc.c			\
	  buttons.c 		\
	  check_point.c 	\
	  color_buttons.c   \

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
		make -C libft/
		gcc -o $(NAME) $(BINS) -L. libft/libft.a $(MLX)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -o $@ $<

clean:
	 /bin/rm -f $(BINS)
	 make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
