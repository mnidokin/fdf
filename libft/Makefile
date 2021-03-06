# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 10:54:09 by mnidokin          #+#    #+#              #
#    Updated: 2020/11/21 22:47:10 by mnidokin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
COMP =		gcc
COMP_FLAG = -Wall -Werror -Wextra -O3 -c

HEADERS_FILES =	libft.h \
				get_next_line.h
HEADERS_DIR =	./includes/
HEADERS =		$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))
INCLUDES =		-I $(HEADERS_DIR)

SRC = 		$(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_DIR = 	./src/
SRC_FILES = ft_atoi.c\
    		ft_bzero.c\
    		ft_isalnum.c\
  		  	ft_isalpha.c\
  		  	ft_isascii.c\
  		  	ft_isdigit.c\
  		  	ft_islow.c\
			ft_isprint.c\
			ft_isup.c\
			ft_itoa.c\
			ft_lstadd.c\
			ft_lstadd_back.c\
			ft_lstat.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_numlen.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_strndup.c\
			ft_sqrt.c\
			ft_add_char.c\
			get_next_line.c

OBJ_DIR = 	./obj/
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ = 		$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all	: $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)
	@ echo "\n\033[37;1;42m libft.a done \033[0m"

$(OBJ_DIR) : 
	@ mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@ $(COMP) $(COMP_FLAG) $(INCLUDES) $< -o $@
	@ echo "\033[31m.\033[0m\c"

clean :
	@ rm -rf $(OBJ_DIR)

fclean : clean
	@ rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
