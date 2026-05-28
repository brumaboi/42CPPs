# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 13:11:46 by sbruma            #+#    #+#              #
#    Updated: 2026/05/27 14:06:22 by sbruma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++17
RM		= rm -f

SRC		= main.cpp BitcoinExchange.cpp
		  
OBJ_DIR	= obj
OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

TEST_DIR	= tests

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	@mkdir -p $(TEST_DIR)
	@printf "date | value\n2011-01-03 | 3\n2011-01-03 | 2\n2011-01-03 | 1\n2011-01-03 | 1.2\n2011-01-09 | 1\n2012-01-11 | -1\n2001-42-42\n2012-01-11 | 1\n2012-01-11 | 2147483648\n" \
		> $(TEST_DIR)/subject.txt
	@printf "date | value\n2009-01-02 | 0\n2010-08-20 | 1\n2011-01-01 | 100\n2012-06-16 | 0.5\n2013-04-09 | 2\n2014-07-03 | 1000\n2021-12-31 | 1\n" \
		> $(TEST_DIR)/valid.txt
	@printf "date | value\n2008-12-31 | 1\n2009-01-01 | 1\n2009-01-02 | 1\n2022-03-29 | 1\n2099-01-01 | 1\n" \
		> $(TEST_DIR)/edge_dates.txt
	@printf "date | value\n2011-01-01 | 0\n2011-01-01 | 0.001\n2011-01-01 | 1000\n2011-01-01 | 1001\n2011-01-01 | -0.5\n2011-01-01 | 999.99\n2011-01-01 | abc\n2011-01-01 | \n" \
		> $(TEST_DIR)/edge_values.txt
	@printf ""  > $(TEST_DIR)/empty.txt
	@printf "date | value\n" > $(TEST_DIR)/header_only.txt
	@printf "\n\n\n" > $(TEST_DIR)/whitespace_only.txt
	@printf "date | value\n2013-13-01 | 1\n2012-02-30 | 1\n0000-01-01 | 1\n2011/01/03 | 1\n2011-1-3 | 1\n2011-01-03x | 1\n20110103 | 1\n" \
		> $(TEST_DIR)/bad_dates.txt
	@printf "date | value\n2011-01-01 | 1000.0\n2011-01-01 | 1000.001\n2011-01-01 | -0\n2011-01-01 | +5\n2011-01-01 | 1e2\n2011-01-01 |  \n2011-01-01| 1\n2011-01-01 |1\n" \
		> $(TEST_DIR)/tricky_values.txt

tclean:
	$(RM) -rf $(TEST_DIR)

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean tclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean tclean re test