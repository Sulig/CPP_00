# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 17:01:41 by sadoming          #+#    #+#              #
#    Updated: 2024/09/10 17:01:41 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
# ------------------ #
# Flags:

CC		 = g++
CFLAGS	 = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98
# ------------------- #
# Sources:
MAK = Makefile
SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

#-------------------------------------------------------------#
all: $(NAME)
#-------------------------------------------------------------#
author:
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "   ~ \t      Made by Sadoming \t        ~\n"
	@echo "~ **************************************** ~\n\n"
#-------------------------------------------------------------#
# **************************************************************************** #
# COMPILATION ->
%.o: %.cpp $(MAK)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ---
$(NAME): $(MAK) $(OBJ)
	@echo "\033[1;93m\n * Making $(NAME) -->\033[0;37m\n"
	$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) -o $@
	@echo "\033[1;32m\n $(NAME) Compiled Successfully\033[0;37m\n"

# **************************************************************************** #
# Clean region
clean:
	@rm $(OBJ)

fclean:	clean
	@rm $(NAME)
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all

.PHONY:	all author clean clear fclean re
# **************************************************************************** #