# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 15:12:39 by aehrl             #+#    #+#              #
#    Updated: 2026/02/08 21:15:18 by aehrl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind
CC = c++ -Wall -Wextra -Werror -std=c++98
# add include  (-I) so that i can do <easyfind>
SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Creating $(END)"
	@$(CC) $(OBJ) -o $(NAME)

%.o:%.cpp
	@echo "$(BLUE)Compiling $(END)"
	$(CC) -c $< -o $@

clean:
	@echo "$(RED)Deleting $(OBJ) $(END)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Deleting $(NAME) $(END)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
