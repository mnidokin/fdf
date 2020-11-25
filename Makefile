NAME = fdf

SRC =	./src/main.c
		./src/ft_error.c
		./src/ft_read.c
		./src/ft_scaling.c

LIBFT = ./libft

MLX = ./minilibx_macos

LIB_MAC = -lmlx -lm -lft -L $(LIBFT) -L $(MLX) -framework OpenGL -framework APPKit

FLAGS = -Wall -Werror -Wextra

INC = -I ./libft/includes/ -I ./includes/

all: $(NAME)

lib_compile:
	make -C $(LIBFT)
	make -C $(MLX)

$(NAME): lib_compile
	gcc $(FLAGS) $(INC) -o $(NAME) $(SRC) $(LIB_MAC)

clean:
	make -C $(LIBFT) fclean
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
