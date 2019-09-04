# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 23:38:04 by hbhuiyan          #+#    #+#              #
#    Updated: 2019/08/12 21:40:01 by hbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	./*.c ./ft_printf/src/*.c

INCLUDES = ./libft.h ./ft_printf/includes/ft_printf.h

OBJECTS = *.o

FLAGS = -Wall -Wextra -Werror

$(NAME): $(SRC)/%.o
	@gcc -g $(FLAGS) -c $(SRC) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

all: $(NAME)

clean :
	@rm -fr $(OBJ)
	@find . -type f -name '*.o' -delete

fclean : clean
	@rm -fr $(NAME)
re :
	@make fclean
	@make all
