# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:09:11 by ccadoret          #+#    #+#              #
#    Updated: 2023/11/21 16:09:14 by ccadoret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_atoi.c ft_strlen.c ft_instruct2.c ft_instruct_1.c ft_isdigit.c\
	push_swap.c ft_split.c push_swap_utilis.c indexage.c push_swap_inf20.c

PTF_DIR = ft_printf

PTF_SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
            ft_printf.h ft_putnbr_base.c ft_putptr.c ft_strlen.c

OBJ = $(addprefix $(PTF_DIR)/, $(PTF_SRCS:.c=.o)) $(SRCS:.c=.o)

NAME = push_swap

FLAGS = gcc -Wall -Wextra -Werror -I./ft_printf

all: $(NAME)

$(PTF_DIR)/%.o: $(PTF_DIR)/%.c
	$(FLAGS) -c $< -o $@

%.o: %.c
	$(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf *.o $(PTF_DIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
