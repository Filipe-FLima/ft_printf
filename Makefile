# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 14:49:01 by flima             #+#    #+#              #
#    Updated: 2024/10/22 17:26:42 by flima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

DIR_LIBFT = Libft

LIBFT = ./Libft/libft.a

INCLUDE = -I $(DIR_LIBFT)

AR = ar -rcs

SRCS = ft_printf.c ft_utils.c ft_nbr_tohex.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
		@$(MAKE) -C $(DIR_LIBFT)

$(NAME): $(LIBFT) $(OBJS)
		cp $(LIBFT) $(NAME)
		@$(AR) $(NAME) $(OBJS) $(LIBFT)

	
%.o:%.c
		$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDE)
	
clean:
		$(MAKE) clean -C $(DIR_LIBFT)
		rm -f $(OBJS)

fclean: clean
		$(MAKE) fclean -C $(DIR_LIBFT)
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 