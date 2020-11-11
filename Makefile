# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icanker <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/14 12:57:19 by icanker           #+#    #+#              #
#    Updated: 2020/08/14 12:57:25 by icanker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -o2

SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = -I libft/include -I include
LIBS = -L libft

SRC = bellman_ford copy_links_and_rooms end_with_error find_new_ways finding_paths hash links main parsing print_map rooms run_ants short_way short_way_utilities short_way_utilities2 suurballe free_lem
INC = include/lem_in.h

SRC_C = $(patsubst %, %.c, $(SRC))

OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %, %.o, $(SRC)))

.PHONY: all clean fclean re make_lib

all: $(NAME)

$(OBJ_DIR):
	mkdir -vp obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all
