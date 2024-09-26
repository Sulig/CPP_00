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

NAME = AwesomePhoneBook
# ------------------ #
# Flags:

CC		 = g++
CFLAGS	 = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98
INCLUDE = -I $(DIR_INC)/
# ------------------- #
# Directories:

DIR_INC	= ./inc
DIR_SRC	= ./src
DIR_OBJ	= ./obj
# ------------------- #
# Sources:
MAK = Makefile
HDR = $(DIR_INC)/ # Headers

SRC_SRC = AwesomePhoneBookMain.cpp Contact.cpp PhoneBook.cpp

SRC = $(addprefix $(DIR_SRC)/, $(SRC_SRC))
OBJS = $(patsubst $(DIR_SRC)%.cpp, $(DIR_OBJ)/%.o, $(SRC))
# **************************************************************************** #
#-------------------------------------------------------------#
all: $(NAME)
#-------------------------------------------------------------#
author:
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "   ~ \t      Made by Sadoming \t        ~\n"
	@echo "~ **************************************** ~\n\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME)"
	@echo "\n~ **************************************** ~\033[0;37m\n"
	@./$(NAME)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# **************************************************************************** #
# COMPILATION ->

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HDR) $(MAK)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(INCLUDE)

$(NAME): $(MAK) $(HDR) $(OBJS)
	@echo "\033[1;93m\n * Making $(NAME) -->\033[0;37m\n"
	$(CC) $(OBJ) $(CFLAGS) -o $@
	@echo "\033[1;32m\n $(NAME) Compiled Successfully\033[0;37m\n"

# **************************************************************************** #
# **************************************************************************** #
# Debugging region:

debug: $(NAME)
	@echo " ~ Debugging ./$(NAME)"
	@lldb $(NAME)

# ------------------

val: $(NAME)
	@echo " ~ Running valgrind ./$(NAME)"
	@valgrind ./$(NAME)

val-strict: $(NAME)
	@echo " ~ Running valgrind ./$(NAME)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
# **************************************************************************** #
# Clean region
clean:
	@make -s clean -C $(LIB_DIR)
	@/bin/rm -frd $(OBJ_DIR)

fclean:	clean
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all

.PHONY:	all author clean clear debug fclean re run val val-strict
# **************************************************************************** #