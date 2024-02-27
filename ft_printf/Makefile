# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 15:09:54 by ccadoret          #+#    #+#              #
#    Updated: 2023/10/21 17:00:47 by ccadoret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c\
	ft_putnbr_base.c ft_putptr.c ft_putstr.c\
	ft_strlen.c ft_putnbr.c

OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I ./

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
		cc $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
