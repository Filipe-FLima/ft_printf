# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:49:01 by flima             #+#    #+#              #
#    Updated: 2024/10/27 17:45:55 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra 
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a
AR = ar -rcs
INCUDE = -Ilibft
SRCS = ft_printf.c ft_utils.c ft_nbr_tohex.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
		make -C $(DIR_LIBFT)

$(NAME): $(LIBFT) $(OBJS)
		@cp $(LIBFT) $(NAME)
		@$(AR) $(NAME) $(OBJS)
	
%.o:%.c ft_printf.h
		$(CC) $(CFLAGS) $(INCUDE) -c -o $@ $<

clean:
		make -C $(DIR_LIBFT) clean
		rm -f $(OBJS)

fclean: clean
		make -C $(DIR_LIBFT) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 