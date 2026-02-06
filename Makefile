# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgervet <42@leogervet.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 0026/02/01 11:08:40 by gervet            #+#    #+#              #
#    Updated: 2026/02/06 11:43:41 by lgervet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

MLXPATH	:= libs/minilibx-linux
MLXNAME	:= libmlx.a
MLX		:= $(MLXPATH)/$(MLXNAME)
LIBPATH	:= libs/libft
LIBNAME	:= libft.a
LIBFT	:= $(LIBPATH)/$(LIBNAME)

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g3
INCLUDES:= -I includes -I $(MLXPATH) -I $(LIBPATH)/includes
LDFLAGS	:= -L $(MLXPATH) -lmlx -L $(LIBPATH) -lft -lXext -lX11 -lm -lz

SRCS	:= \
		srcs/so_long.c \
		srcs/utils/exit_handler.c \
		srcs/utils/graphics.c \
		srcs/parsing/file_parser.c \
		srcs/parsing/file_validator.c \
		srcs/graphics/window_manager.c \
		srcs/graphics/draw_map.c
OBJS	:= $(SRCS:.c=.o)

######## RULES ########

all: $(NAME)

# *** Compilation *** #
$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLXPATH)

$(LIBFT):
	$(MAKE) -C $(LIBPATH)

# ***** Others ***** #

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBPATH) clean
	-$(MAKE) -C $(MLXPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBPATH) clean

re: fclean all

.PHONY: all clean fclean re

