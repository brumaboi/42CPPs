# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 19:00:12 by sbruma            #+#    #+#              #
#    Updated: 2025/01/21 19:04:22 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= megaphone.cpp
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
