# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:50:29 by nasamadi          #+#    #+#              #
#    Updated: 2023/01/27 15:56:46 by nasamadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

# Minilibx
MLX_PATH	= ./minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I $(LIBFT_PATH)./includes/\
				-I $(MLX_PATH)

# Sources
SRC_PATH	=	./sources/
SRC			=	\
				fractol.c\
					init.c\
					draw.c\
					fractal_mandelbrot.c\
					fractal_julia.c\
					fractal_burning_ship.c\
					fractal_mandelbar.c\
					fractal_celtic_mandelbrot.c\
					fractal_celtic_mandelbar.c\
					fractal_celtic_perpendicular.c\
					fractal_perpendicular_mandelbrot.c\
					fractal_perpendicular_burning_ship.c\
					fractal_perpendicular_buffalo.c\
					color.c\
					controls_keyboard.c\
					controls_mouse.c\
					controls_utils.c\
					print.c\
					utils.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
