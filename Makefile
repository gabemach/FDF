# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmachado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 13:55:38 by gmachado          #+#    #+#              #
#    Updated: 2019/08/19 18:43:39 by gmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFILES = srcs/*.c

OFILES = srcs/*.o

all: $(NAME)

$(NAME):
	make -C srcs/libft
	make -C srcs/minilibx_macos_sierra
	gcc -Wall -Wextra -Werror -I ./srcs/fdf.h -o ./srcs/makewin.o -c ./srcs/makewin.c
	gcc -Wall -Wextra -Werror -I ./srcs/fdf.h -o ./srcs/pointloc.o -c ./srcs/pointloc.c
	gcc -Wall -Wextra -Werror -I ./srcs/fdf.h -o ./srcs/shift.o -c ./srcs/shift.c
	gcc -Wall -Wextra -Werror -I ./srcs/fdf.h -o ./srcs/drawlines.o -c ./srcs/drawlines.c
	gcc -Wall -Wextra -Werror -o $(NAME) ./srcs/makewin.o ./srcs/pointloc.o ./srcs/shift.o ./srcs/drawlines.o ./srcs/minilibx_macos_sierra/libmlx.a -L ./srcs/minilibx_macos_sierra -lmlx -L srcs/libft -lft -framework OpenGL -framework Appkit

clean:
	make -C srcs/libft clean
	make -C srcs/minilibx_macos_sierra clean
	rm -f $(OFILES)

fclean: clean
	make -C srcs/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
