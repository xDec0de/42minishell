# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 20:23:54 by daniema3          #+#    #+#              #
#    Updated: 2025/04/07 18:26:04 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fdiagnostics-color=always

SRC_DIR = ./src
OBJ_DIR = ./objs

# > ~ Main project files

SRCS =	minishell.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -n "\r⏳ \e[0;33mCompiling $(notdir $<)\e[0m                          "
	@{\
		ERR=$$( ($(CC) $(CFLAGS) -c $< -o $@) 2>&1 );\
		if [ $$? -ne 0 ]; then\
			echo -n "\r❌ \e[0;31mFailed to compile $(notdir $<):        \e[0m";\
			echo "\n$$ERR";\
			exit 1;\
		fi;\
	}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline
	@echo -n "\r✅ \e[1;36m$(NAME) \e[0;32msuccessfully compiled!               "
	@echo 

clean:
	@echo -n "\r⏳ \e[0;33mRemoving $(NAME) objs.                               "
	@rm -rf $(OBJ_DIR)
	@echo -n "\r✅ \e[0;32mSuccessfully removed $(NAME) objs.                   "
	@echo 

fclean: clean
	@echo -n "\r⏳ \e[0;33mRemoving $(NAME) executable.                         "
	@rm -rf $(NAME)
	@echo -n "\r✅ \e[0;32mSuccessfully removed $(NAME) executable.             "
	@echo 

re: fclean $(NAME)

.PHONY: all clean fclean re
