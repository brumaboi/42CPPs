# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 13:13:19 by sbruma            #+#    #+#              #
#    Updated: 2026/05/27 14:44:00 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= main.cpp RPN.cpp
		  
OBJ_DIR	= obj
OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	@echo "--- Test 1: 8 9 * 9 - 9 - 9 - 4 - 1 + ---"
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "--- Test 2: 7 7 * 7 - ---"
	./$(NAME) "7 7 * 7 -"
	@echo "--- Test 3: 1 2 * 2 / 2 * 2 4 - + ---"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo "--- Test 4: (1 + 1) ---"
	./$(NAME) "(1 + 1)" ; true

.PHONY: all clean fclean re test