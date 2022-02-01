# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 09:58:31 by mgolinva          #+#    #+#              #
#    Updated: 2022/02/01 14:26:02 by mgolinva         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = baby_anim.c exit_anim.c img_set_up.c ft_texturingue.c move.c utils.c wall_anim.c ft_map_checker.c ft_map_maker.c line_ct.c so_long.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

INCL = so_long.h get_next_line/get_next_line.h minilibx_opengl_20191021/mlx.h

MLXA = minilibx_opengl_20191021/libmlx.a

OBJS = $(SRCS:.c=.o)

CC = gcc 

FLAGS = -Wall -Wextra -Werror

MLXCC = -Imlx -framework OpenGL -framework AppKit

RM = rm -f

%.o: %.c $(SRCS)
	$(CC) -c $< -o $@

NAME = so_long

all: mlx $(NAME)

mlx: 
	$(MAKE) -C ./minilibx_opengl_20191021/

$(NAME): $(OBJS) $(INCL)
	@$(CC) $(FLAGS) -c $(SRCS) -I $(INCL)
	@$(CC) $(FLAGS) $(MLXCC) -o $(NAME) $(OBJS) $(MLXA)

clean:
	$(MAKE) clean -C ./minilibx_opengl_20191021/

fclean: clean
	$(MAKE) fclean -C ./minilibx_opengl_20191021/
	$(RM) $(NAME)

re : clean all

.PHONY: make clean fclean re
