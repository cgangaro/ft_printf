# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 10:46:00 by cgangaro          #+#    #+#              #
#    Updated: 2021/01/20 11:41:33 by cgangaro         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
FLAGS 		= -Wall -Wextra -Werror -c
DEPS		= ft_printf.h
SRCS		= 	ft_printf.c \
				ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_index.c \
				ft_itoa_base.c \
				ft_printf.c \
				ft_printf_index.c \
				ft_printf_index_2.c \
				ft_printf_utils.c \
				ft_printf_utils_2.c \
				ft_search.c \
				ft_strlen.c \
				ft_substr.c	\
				ft_cas_spe.c \
				ft_add_char.c \
				ft_suprr_char.c	\
				ft_cas_spe_nbr_neg.c \
				ft_index_2.c \
				ft_cas_spe_point.c \
				ft_itoa_base_p.c \
				ft_fin.c \
				ft_printf_arg.c \
				ft_printf_aff.c

OBJS = ${SRCS:%.c=%.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	gcc $(FLAGS) $< -o $@

clean:
			rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re
