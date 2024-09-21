# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 16:53:22 by ngoulios          #+#    #+#              #
#    Updated: 2024/09/21 19:05:22 by ngoulios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                PHONY TARGETS                                 #
# **************************************************************************** #
.PHONY: all libft libmlx42 clean fclean re

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME = fractol

# Paths to submodules
LIBFT_DIR = lib/libft
LIBMLX42_DIR = lib/MLX42

# Compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -I$(LIBFT_DIR)/include -I$(LIBMLX42_DIR)/include 

# Source files
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX42 = $(LIBMLX42_DIR)/build/libmlx42.a

# Linker Flags
LIBS = $(LIBFT) $(LIBMLX42) -ldl -lglfw -pthread -lm
MLX42_LDFLAGS = -L$(LIBMLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

# **************************************************************************** #
#                                      RULES                                   #
# **************************************************************************** #

all: libft libmlx42 $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

libmlx42:
	@mkdir -p $(LIBMLX42_DIR)/build
	@cd $(LIBMLX42_DIR)/build && cmake .. && make

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX42)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX42_LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX42_DIR)/build clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBMLX42_DIR)/build fclean

re: fclean all

# **************************************************************************** #
#                                    END OF FILE                               #
# **************************************************************************** #
