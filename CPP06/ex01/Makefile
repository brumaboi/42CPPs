# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 16:15:31 by marvin            #+#    #+#              #
#    Updated: 2025/09/28 16:15:31 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= serializer
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= Serializer.cpp \
		  main.cpp
		  
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