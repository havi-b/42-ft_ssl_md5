# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 05:31:07 by hbhuiyan          #+#    #+#              #
#    Updated: 2019/08/14 01:09:09 by hbhuiyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	ft_ssl

SRC =	./src/*.c

OBJ =  *.o


FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@make -C ./libft re
	@gcc -g $(FLAGS) -c $(SRC)
	@gcc -g $(FLAGS) -L ./libft -lft $(OBJ) -o $(NAME)

clean :
	@rm -fr $(OBJ)
	@find . -type f -name '*.o' -delete
	@find . -type f -name '*.gch' -delete

fclean : clean
	@make -C ./libft/ fclean
	@rm -fr $(NAME)
re :
	@make fclean
	@make all