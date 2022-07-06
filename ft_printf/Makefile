# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 22:24:04 by wmozella          #+#    #+#              #
#    Updated: 2021/11/30 22:26:47 by wmozella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

C_FILES =		ft_printf.c			ft_itoa_base.c		ft_itoa.c		ft_itoa_base_up.c


OBJ = $(patsubst %.c,%.o,$(C_FILES))
CC = gcc
FLAGS = -Wall -Werror -Wextra -I$(HEADER)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all