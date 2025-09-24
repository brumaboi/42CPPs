# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/16 14:06:48 by marvin            #+#    #+#              #
#    Updated: 2025/09/24 20:25:51 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= AForm.cpp \
		  Bureaucrat.cpp \
		  PresidentialPardonForm.cpp \
		  RobotomyRequestForm.cpp \
		  ShrubberyCreationForm.cpp \
		  Intern.cpp \
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
