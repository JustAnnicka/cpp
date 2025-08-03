NAME = MyAwesomePhonebook
CC = c++ -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all:$(NAME)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating $(NAME)$(END)"
	@$(CC) $(OBJ) -o $(NAME)

%.o:%.cpp
	@echo "$(BLUE)Compiling$(END)"
	@$(CC) -c $< -o $@

clean:
	@echo "$(RED)Deleting $(OBJ) $(END)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Deleting $(NAME) $(END)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

