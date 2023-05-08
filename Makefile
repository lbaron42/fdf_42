# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaron <lbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:42:30 by lbaron            #+#    #+#              #
#    Updated: 2022/12/04 20:56:54 by lbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I./libft -I./get_next_line -I./minilibx_linux

AR = ar -rc

CC = cc

RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
NC = \033[0m

OBJ_DIR = obj

LIBFT_DIR = ./libft/
GNL_DIR = ./get_next_line/
MINILIBX_DIR = ./minilibx-linux/

LIBFT = $(LIBFT_DIR)libft.a
GNL = $(GNL_DIR)gnl.a
MINILIBX = $(MINILIBX_DIR)libmlx.a

SRC= fdf.c magic_func.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)


all:$(NAME)

$(NAME):$(MINILIBX) $(LIBFT) $(GNL) $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(GNL) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)FDF successfully created!$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(GNL):
	@make -s -C $(GNL_DIR)

$(MINILIBX):
	@make -s -C $(MINILIBX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ)
	@make -s clean -C $(LIBFT_DIR)
	@make -s clean -C $(GNL_DIR)
	@make -s clean -C $(MINILIBX_DIR)
	@echo "$(GREEN)FDF Object files cleaned!$(NC)"

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@make -s fclean -C $(GNL_DIR)
	@make -s clean -C $(MINILIBX_DIR)
	@echo "$(GREEN)FDF Object files cleaned!$(NC)"
	@echo "$(GREEN)FDF cleaned!\n$(NC)"

re: fclean all

.PHONY: all clean fclean re
