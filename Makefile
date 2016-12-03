# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfilipch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 09:34:02 by mfilipch          #+#    #+#              #
#    Updated: 2016/10/09 23:56:07 by mfilipch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME1		=	checker

FUNC0		=	push_swap.c
FUNC1		=	checker.c

FUNCS		+=	sorting.c\
				psw_op.c\
				add_check.c

LIBFT		=	./libft/libft.a
LIBINC		=	-I./libft
LIBLINK		=	-L./libft -lft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJ0		=	$(addprefix $(OBJS_DIR), $(FUNC0:.c=.o))
OBJ1		=	$(addprefix $(OBJS_DIR), $(FUNC1:.c=.o))
OBJS		=	$(addprefix $(OBJS_DIR), $(FUNCS:.c=.o))

INC_DIR		=	./includes/
OBJS_DIR	=	./build/

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

build:
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.c | build
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INC_DIR) -c $(FUNC0) -o $(OBJ0)
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INC_DIR) -c $(FUNC1) -o $(OBJ1)
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INC_DIR) -c $< -o $@

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJ0) $(OBJS) $(LIBLINK)
	@$(CC) -o $(NAME1) $(OBJ1) $(OBJS) $(LIBLINK)

clean:
	@/bin/rm -rf $(OBJS_DIR)
	@make -C ./libft clean
	@/bin/rm -f *.out
	@/bin/rm -f ._*
	@/bin/rm -f .DS*

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(NAME1)
	@make -C ./libft fclean

re: fclean all
