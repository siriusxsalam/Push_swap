# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasalam <hasalam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 15:30:14 by hasalam           #+#    #+#              #
#    Updated: 2023/05/10 23:57:53 by hasalam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS = action_helper.c\
		actions.c\
		ft_errors.c\
		ft_helper1.c\
		ft_helper2.c\
		ft_lib.c\
		ft_lib2.c\
		ft_split.c\
		ft_strjoin.c\
		linked_list.c\
		parssing.c\
		print_action.c\
		push_swap.c\
		swap_chanks.c

SRCS_BONUS = checker.c\
				action_helper.c\
				actions.c\
				print_action.c\
				ft_errors.c\
				ft_lib2.c\
				ft_lib.c\
				ft_split.c\
				ft_strjoin.c\
				linked_list.c\
				parssing.c\
				ft_helper1.c\
				get_next_line.c\
				get_next_line_utils.c\
				ft_helper2.c

CC = cc
RM = rm -f
CFALGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all: ft_printf/libftprintf.a $(NAME)

ft_printf/libftprintf.a:
	make -C ft_printf

%.o:%.c push_swap.h
	${CC} ${CFALGS} -c $<

$(NAME): $(OBJS)
	$(CC) $(CFALGS) $(OBJS) ft_printf/libftprintf.a -o $(NAME)

bonus: ft_printf/libftprintf.a $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFALGS) $(OBJS_BONUS) ft_printf/libftprintf.a -o $(NAME_BONUS)

clean:
	${RM} ${OBJS} $(OBJS_BONUS)
	make fclean -C ft_printf

fclean: clean
	${RM} ${NAME} $(NAME_BONUS)

re: fclean all

.PHONY: fclean clean re all