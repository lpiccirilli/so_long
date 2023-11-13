# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpicciri <lpicciri@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 20:09:00 by lpicciri          #+#    #+#              #
#    Updated: 2023/11/13 14:49:44 by lpicciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
PRINTF_PATH		=	./ft_printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a


SOURCES_FILES	=	so_long.c map_check.c check_letters.c mlx_data.c check_walls.c create_map.c moves.c utils.c\

HEADER			=	./so_long.h

OBJECTS			= 	$(SOURCES_FILES:.c=.o)

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror -g

MLX_FLAGS		=	-lmlx -Lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) ${CFLAGS} -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT) $(MINILIBX) $(PRINTF)
				$(CC) $(OBJECTS) $(LIBFT) $(MINILIBX) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

$(PRINTF):
				make -C $(PRINTF_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${MINILIBX_PATH}
				make clean -C ${PRINTF_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f $(LIBFT)
					rm -f $(MINILIBX)
					rm -f $(PRINTF)

re:				fclean all

.PHONY:			all clean re
