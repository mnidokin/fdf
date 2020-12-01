NAME = fdf

SRC =	./src/ft_abs.c \
		./src/ft_draw_map.c \
		./src/ft_draw.c \
		./src/ft_error.c \
		./src/ft_height_map.c \
		./src/ft_isbigger.c \
		./src/ft_iso.c \
		./src/ft_key.c \
		./src/ft_offset.c \
		./src/ft_read.c \
		./src/ft_rotation.c \
		./src/ft_scale.c \
		./src/main.c

LIBFT = ./libft

MLX = ./minilibx_macos

LIB_MAC = -lmlx -lm -lft -L $(LIBFT) -L $(MLX) -framework OpenGL -framework APPKit

FLAGS = -Wall -Werror -Wextra

INC = -I ./libft/includes/ -I ./includes/ -I ./minilibx_macos/

all: $(NAME)

lib_compile:
	@ make -C $(LIBFT)
	@ make -C $(MLX)

$(NAME): lib_compile
	@ gcc $(FLAGS) $(INC) -o $(NAME) $(SRC) $(LIB_MAC)

clean:
	@ make -C $(LIBFT) fclean
	@ make -C $(MLX) clean

fclean: clean
	@ rm -f $(NAME)

re: fclean all
