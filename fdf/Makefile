# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoroka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 18:13:07 by asoroka           #+#    #+#              #
#    Updated: 2017/04/01 20:33:01 by asoroka          ###   ########.fr        #
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
	  calculate.c 		\
	  fill_down.c 		\
	  zoom.c 			\
	  print_map.c		\
	  calc.c			\
	  rotation.c      \
	  move.c          \

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
		make -C libft/
		gcc -o $(NAME) $(BINS) -L. libft/libft.a $(MLX)
		clean

%.o: %.c $(HEADER)
		gcc $(FLAGS) -o $@ $<

clean:
	 /bin/rm -f $(BINS)
	 make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
