# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 15:52:34 by aeclipso          #+#    #+#              #
#    Updated: 2020/11/22 16:09:49 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SRCD = ./src/
SRCF = ants.c\
	bfs.c\
	bfs2.c\
	check_v.c\
	cut_line.c\
	cut_line2.c\
	edge_list_operations.c\
	edge_operations.c\
	free_all.c\
	poisk.c\
	print_ant.c\
	vertex_list_operations.c\
	vertex_operations.c\
	zap_edge_ini.c\
	zap_edge_one.c\
	zap_edge_two.c\
	zap_vertex.c\
	dll_add_first.c\
	dll_add_last.c\
	dll_add_n.c\
	dll_get.c\
	dll_get_first.c\
	dll_get_last.c\
	dll_get_n.c\
	dll_length.c\
	dll_new_node.c\
	dll_peek.c\
	dll_peek_first.c\
	dll_peek_last.c\
	dll_peek_n.c\
	dll_pop.c\
	dll_push.c

OBJD = ./obj/
SRC = $(addprefix $(SRCD), $(SRCF))
OBJ = $(addprefix $(OBJD), $(OBJF))
OBJF = $(SRCF:.c=.o)
LIBS = ./libft/libft.a
HEADERS = -I ./include -I ./libft/include
HDR = ./include/lemin.h ./libft/include/libft.h
FLAGS = -Wall -Wextra -Werror -g
CC = gcc
COMP = $(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
RECOMP = $(CC) $(INCLUDES) $(HEADERS) -c $< -o $@

all: obj $(NAME)

obj:
	mkdir -p $(OBJD)

$(NAME): libft/libft.a $(OBJ) $(HDR)
	$(COMP)
	@printf "Compilating lem-in done"

$(OBJD)%.o:$(SRCD)%.c $(HDR)
	$(RECOMP)

clean:
	@make clean -C libft
	@make clean -C dll_lib
	@rm -Rf $(OBJ)
	@rm -Rf obj
	@printf "Clean done\n"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C dll_lib
	@printf "FClean done\n"

libft/libft.a:
	@make -C libft

dll_lib/dll.a:
	@make -C dll_lib

re: fclean all
