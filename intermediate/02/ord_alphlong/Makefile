# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzhao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 10:18:50 by vzhao             #+#    #+#              #
#    Updated: 2019/08/10 10:28:17 by vzhao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ord_alphlong
SRC = *.c
INC = *.h
FLAGS = -Wall -Wextra -Werror -I $(INC)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC)

fclean:
	/bin/rm -f $(NAME)

re: fclean $(NAME)

test: re
	@echo "----------------------------------------------------------"
	./$(NAME) "After all this time Always said Snape" | cat -e
	./$(NAME) "A a b B cc ca cd" | cat -e
	./$(NAME) "Never take a gamble you are not prepared to lose" | cat -e
	./$(NAME) | cat -e
	./$(NAME) "Hello" "it's" "me" | cat -e
	./$(NAME) "" | cat -e
	@echo "-----------------------------------------------------------"
