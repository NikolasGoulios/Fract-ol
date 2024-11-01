# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 17:58:04 by ngoulios          #+#    #+#              #
#    Updated: 2024/11/01 18:10:52 by ngoulios         ###   ########.fr        #
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

LIBFT_DIR = ./lib/libft
LIBMLX42_DIR = ./lib/MLX42

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iinclude -I$(LIBFT_DIR)/include -I$(LIBMLX42_DIR)/include 

SRC = src/events.c src/initialize.c src/main.c src/render.c src/sets.c src/utils.c src/calculations.c src/colors.c src/parsing.c
OBJ = $(SRC:src/%.c=obj/%.o)

# Create obj directory if it doesn't exist
OBJ_DIR = obj
$(shell mkdir -p $(OBJ_DIR))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX42 = $(LIBMLX42_DIR)/build/libmlx42.a

# Linker Flags
LIBS = $(LIBFT) $(LIBMLX42) -ldl -lglfw -lm

# **************************************************************************** #
#                                      RULES                                   #
# **************************************************************************** #

# Default rule
all: libft libmlx42 $(NAME)

# Build libft
libft:
	@$(MAKE) -C $(LIBFT_DIR)

# Build MLX42
libmlx42:
	@mkdir -p $(LIBMLX42_DIR)/build
	@cd $(LIBMLX42_DIR)/build && cmake .. && make

# Build fractol
$(NAME): $(OBJ) $(LIBFT) $(LIBMLX42)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(INCLUDES) -o $(NAME)

# Rule for object files
obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files and libraries
clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX42_DIR)/build clean || true
	rm -rf $(OBJ_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBMLX42_DIR)/build fclean || true
	rm -rf $(OBJ_DIR)

# Rebuild everything
re: fclean all

# **************************************************************************** #
#                                    END OF FILE                               #
# **************************************************************************** #
