# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 20:09:00 by lpicciri          #+#    #+#              #
#    Updated: 2023/09/21 20:23:55 by lpicciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	so_long.c map_check.c mlx_data.c check_walls.c\

HEADER			=	./so_long.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror

MLX_FLAGS		=	-lmlx -Lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)
				$(CC) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f $(LIBFT)

re:				fclean all

.PHONY:			all clean re
