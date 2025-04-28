# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 15:02:03 by skomatsu          #+#    #+#              #
#    Updated: 2025/04/28 18:00:02 by skomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wextra -Wall -Werror

RM = rm -rf

SRCS_DIR = ./srcs
INC_DIR = ./includes

LIB_DIR = ./libft
MLX_DIR = ./minilibx-linux

SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:.c=.o )

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)/includes -I $(MLX_DIR)

LIB_FLAGS = -L$(LIB_DIR) -lft
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C $(MLX_DIR)
		$(MAKE) -C $(LIB_DIR)
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS) -o $(NAME)

.c.o :
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
		
clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(MLX_DIR) clean
		$(MAKE) -C $(LIB_DIR) clean
		
fclean: clean
		$(RM) $(NAME)
		@cd $(LIB_DIR) && $(MAKE) fclean
		@cd $(MLX_DIR) && $(MAKE) clean 

re:		fclean all

.PHONY	: all clean fclean re

		
		