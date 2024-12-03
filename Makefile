# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 17:58:04 by ngoulios          #+#    #+#              #
#    Updated: 2024/12/03 17:53:19 by ngoulios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                PHONY TARGETS                                 #
# **************************************************************************** #
.PHONY: all libft libmlx42 clean fclean re bonus

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus

DIR_LIBFT = ./lib/libft
DIR_LIBMLX42 = ./lib/MLX42
DIR_SRC = ./src
DIR_BONUS = ./src_bonus
DIR_OBJ = $(DIR_SRC)/objects
DIR_OBJ_BONUS = $(DIR_BONUS)/objects_bonus

SOURCES = events.c \
    initialize.c \
    main.c \
    render.c \
    sets.c \
    utils.c \
    calculations.c \
    colors.c \
    parsing.c

SOURCES_BONUS = events_bonus.c \
    initialize_bonus.c \
    main_bonus.c \
    render_bonus.c \
    sets_bonus.c \
    utils_bonus.c \
    calculations_bonus.c \
    colors_bonus.c \
    parsing_bonus.c \
	sets_burningship.c 

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))
SRC_BONUS = $(addprefix $(DIR_BONUS)/,$(SOURCES_BONUS))

OBJECTS = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(SOURCES)))
OBJECTS_BONUS = $(patsubst %.c,$(DIR_OBJ_BONUS)/%.o,$(notdir $(SOURCES_BONUS)))

HEADERS = -I ./include -I $(DIR_LIBMLX42)/include -I $(DIR_LIBFT)
HEADERS_BONUS = -I ./include_bonus -I $(DIR_LIBMLX42)/include -I $(DIR_LIBFT)

MLXLIB = $(DIR_LIBMLX42)/build/libmlx42.a
LIBFT = $(DIR_LIBFT)/libft.a

# MLX42 is dependent on other libraries
MLXLIB_FLAGS = $(DIR_LIBMLX42)/build/libmlx42.a -ldl -lglfw -lm
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP

# **************************************************************************** #
#                                      RULES                                   #
# **************************************************************************** #

# Default rule
all: $(LIBFT) $(MLXLIB) $(NAME)

# Build libft
$(LIBFT):
	@make -C $(DIR_LIBFT)

# Build MLX42
$(MLXLIB):
	@cd $(DIR_LIBMLX42)/build && cmake .. && make

# Build fractol
$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBFT_FLAGS) $(MLXLIB) $(MLXLIB_FLAGS) $(HEADERS) -o $@

# Rule for object files
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Create obj directory if it doesn't exist
$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

# Build bonus
bonus: $(LIBFT) $(MLXLIB) $(OBJECTS_BONUS)
	@$(CC) $(OBJECTS_BONUS) $(LIBFT_FLAGS) $(MLXLIB) $(MLXLIB_FLAGS) $(HEADERS_BONUS) -o $(NAME_BONUS)

# Rule for bonus object files
$(DIR_OBJ_BONUS)/%.o: $(DIR_BONUS)/%.c | $(DIR_OBJ_BONUS)
	@$(CC) $(CFLAGS) $(HEADERS_BONUS) -c $< -o $@

# Create obj_bonus directory if it doesn't exist
$(DIR_OBJ_BONUS):
	@mkdir -p $(DIR_OBJ_BONUS)

# Clean object files and libraries
clean:
	@$(RM) -r $(DIR_OBJ)
	@$(RM) -r $(DIR_OBJ_BONUS)
	@make -C $(DIR_LIBFT) clean

# Clean everything
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make -C $(DIR_LIBFT) fclean

# Rebuild everything
re: fclean all

# **************************************************************************** #
#                                    END OF FILE                               #
# **************************************************************************** #
