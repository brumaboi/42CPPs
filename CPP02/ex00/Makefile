# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 18:07:26 by sbruma            #+#    #+#              #
#    Updated: 2025/01/23 18:08:17 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fixed
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= main.cpp Fixed.cpp
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