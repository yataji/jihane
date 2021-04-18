# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 11:57:48 by yataji            #+#    #+#              #
#    Updated: 2021/04/18 14:17:55 by jiqarbac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

SRC  =	main.c\
		math.c\
		mathnorm.c\
		tools.c\
		free.c\
		sphere.c\
		cylinder.c\
		cone.c\
		draw.c\
		plane.c\
		rotation.c\
		sdl.c\
		parse.c\
		camera.c\
		camerap.c\
		lights.c\
		obj_cone.c\
		obj_cylinder.c\
		obj_plane.c\
		obj_sphere.c\
		parse_check.c\
		stock.c\
		init_parce.c\

HEADER = 	includes/rt.h


OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME 	= RT

CFLAGS = -Wall -Wextra -Werror 

INCLUDE	= -I /Users/$$USER/.brew/Cellar/sdl2/2.0.14_1/include/ \
	-I /Users/$$USER/.brew/Cellar/sdl2_image/2.0.5/include \
	-I includes

LIB = -L /Users/$$USER/.brew/Cellar/sdl2/2.0.14_1/lib \
	-L /Users/$$USER/.brew/Cellar/sdl2_image/2.0.5/lib \

SDL = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image 

OBJ_DIR = ./obj

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = @gcc 

SRC_DIR = ./srcs
all : $(NAME)

$(LIBFT_LIB): force
	@make -C $(LIBFT_DIR)

force:

$(NAME) : $(LIBFT_LIB) $(OBJ)
	@gcc $(OBJ) $(CFLAGS) -o $(NAME) $(INCLUDE) $(LIB)  $(SDL) $(LIBFT_LIB)
	@echo "\033[92mDone for RT\033[0m"

$(OBJ_DIR):
	@-mkdir $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER) | $(OBJ_DIR)
	@gcc -c  $(INCLUDE) $< -o $@ 

clean :
	@make clean -C ./libft/
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ./libft/
	@rm -rf $(NAME)

norme:
	@norminette **/*.c
	@norminette **/*.h

re : fclean all

