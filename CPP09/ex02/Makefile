# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 13:13:29 by sbruma            #+#    #+#              #
#    Updated: 2026/02/18 13:13:29 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= main.cpp PmergeMe.cpp
		  
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

test: test_valid test_invalid test_large

test_valid: $(NAME)
	@echo "==================="
	@echo " Valid Input Tests"
	@echo "==================="
	@echo ""
	@printf "\033[33mTest 1: Subject example - 5 elements\033[0m\n"
	@./$(NAME) 3 5 9 7 4
	@echo ""
	@printf "\033[33mTest 2: Single element\033[0m\n"
	@./$(NAME) 42
	@echo ""
	@printf "\033[33mTest 3: Two elements\033[0m\n"
	@./$(NAME) 9 1
	@echo ""
	@printf "\033[33mTest 4: Already sorted (even count)\033[0m\n"
	@./$(NAME) 1 2 3 4 5 6
	@echo ""
	@printf "\033[33mTest 5: Reverse sorted (even count)\033[0m\n"
	@./$(NAME) 6 5 4 3 2 1
	@echo ""
	@printf "\033[33mTest 6: Odd number of elements\033[0m\n"
	@./$(NAME) 5 3 1 4 2 7 6
	@echo ""
	@printf "\033[33mTest 7: Already sorted (odd count)\033[0m\n"
	@./$(NAME) 1 2 3 4 5
	@echo ""
	@printf "\033[33mTest 8: Duplicate values\033[0m\n"
	@./$(NAME) 3 1 4 1 5 9 2 6 5 3
	@echo ""
	@printf "\033[33mTest 9: INT_MAX value\033[0m\n"
	@./$(NAME) 2147483647 1 2
	@echo ""

test_invalid: $(NAME)
	@echo "=========================================="
	@echo "Invalid Input Tests (all should print Error)"
	@echo "=========================================="
	@echo ""
	@printf "\033[33mTest 1: Negative number\033[0m\n"
	@./$(NAME) -1 2 || true
	@echo ""
	@printf "\033[33mTest 2: No arguments\033[0m\n"
	@./$(NAME) || true
	@echo ""
	@printf "\033[33mTest 3: Non-numeric input\033[0m\n"
	@./$(NAME) abc || true
	@echo ""
	@printf "\033[33mTest 4: Mixed valid and invalid\033[0m\n"
	@./$(NAME) 1 2 abc 4 || true
	@echo ""
	@printf "\033[33mTest 5: Overflow (> INT_MAX)\033[0m\n"
	@./$(NAME) 9999999999 || true
	@echo ""
	@printf "\033[33mTest 6: Float input\033[0m\n"
	@./$(NAME) 1.5 2 || true
	@echo ""

test_large: $(NAME)
	@echo "=========================================="
	@echo "Large Input Test - 3000 elements from 1-10000"
	@echo "=========================================="
	@echo ""
	@./$(NAME) $(shell shuf -i 1-10000 -n 3000 | tr '\n' ' ')
	@echo ""

.PHONY: all clean fclean re test test_valid test_invalid test_large