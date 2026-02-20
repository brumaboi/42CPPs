# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 13:13:19 by sbruma            #+#    #+#              #
#    Updated: 2026/02/18 13:13:19 by sbruma           ###   ########.fr        #
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

.PHONY: all clean fclean re