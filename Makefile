# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 20:23:54 by daniema3          #+#    #+#              #
#    Updated: 2025/06/12 14:08:35 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_DIR = ./src
OBJ_DIR = ./objs

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3 -fdiagnostics-color=always -I$(SRC_DIR)

# > ~ Main project files

SRCS =	minishell.c

# > ~ Commands

SRCS += cmd/cmd_builder.c \
		cmd/cmd_executor.c \

# > ~ Commands - Builtins

SRCS += cmd/builtin/echo.c \
		cmd/builtin/exit.c

# > ~ Signal

SRCS +=	signal/signal_handler.c

# > ~ Util

SRCS +=	util/ms_exit.c \
		util/ms_malloc.c \
		util/shell_getter.c

# > ~ Array utils

SRCS +=	util/array/ms_arrdup.c \
		util/array/ms_arrfree.c \
		util/array/ms_arrlen.c

# > ~ Char utils

SRCS += util/char/ms_isdigit.c

# > ~ String utils

SRCS +=	util/str/ms_atoi.c \
		util/str/ms_split.c \
		util/str/ms_strdup.c \
		util/str/ms_strequals.c \
		util/str/ms_strlen.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# > ~ Colors!

RED = \e[0;31m
BRED = \e[1;31m
GREEN = \e[1;32m
YLW = \e[0;33m
BYLW = \e[1;33m
BLUE = \e[1;36m
GRAY = \e[0;30m
RES = \e[0m                                                                   

WNAME = $(BYLW)$(NAME)$(YLW)
OKNAME = $(BLUE)$(NAME)$(GREEN)
ERRNAME = $(BRED)$(NAME)$(RED)

# > ~ Compile

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -n "\r⏳ $(YLW)Compiling $(BYLW)$(notdir $<)$(GRAY)...$(RES)"
	@{\
		ERR=$$( ($(CC) $(CFLAGS) -c $< -o $@) 2>&1 );\
		if [ $$? -ne 0 ]; then\
			echo -n "\r❌ $(RED)Failed to compile $(BRED)$@$(GRAY):$(RES)";\
			echo "\n$$ERR";\
			exit 1;\
		fi;\
	}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline
	@echo -n "\r✅ $(OKNAME) successfully compiled!$(RES)"
	@echo 

# > ~ Cleaning

clean:
	@echo -n "\r⏳ $(YLW)Removing $(WNAME) objs.$(RES)"
	@rm -rf $(OBJ_DIR)
	@echo -n "\r✅ $(GREEN)Removed $(OKNAME) objs$(GRAY).$(RES)"
	@echo 

fclean: clean
	@echo -n "\r⏳ $(YLW)Removing $(WNAME) executable$(GRAY)...$(RES)"
	@rm -rf $(NAME)
	@echo -n "\r✅ $(GREEN)Removed $(OKNAME) executable$(GRAY).$(RES)"
	@echo 

# > ~ Clean & compile

re: fclean $(NAME)

# > ~ Norminette check

norm:
	@echo -n "\r⏳ $(YLW)Executing norminette on $(WNAME)$(GRAY)...$(RES)"
	@norminette $(SRC_DIR) | grep "Error:" > norm_errors.txt || true
	@if [ -s norm_errors.txt ]; then \
		echo -n "\r❌ $(RED)Norm errors found on $(ERRNAME)$(GRAY):$(RES)\n";\
		cat norm_errors.txt | sed 's/^Error:/-/'; \
	else \
		echo -n "\r✅ $(GREEN)No norm errors found on $(OKNAME)!$(RES)\n"; \
	fi
	@rm -f norm_errors.txt

build: norm re

# > ~ Tests

TEST_NAME = test_$(NAME)

TEST_DIR = ./test
UNITY_DIR = $(TEST_DIR)/unity

TEST_INC = -I$(UNITY_DIR)/src -I./include

TEST_SRC =	$(filter-out $(SRC_DIR)/minishell.c, $(SRCS)) \
			$(TEST_DIR)/test_minishell.c \
			$(UNITY_DIR)/src/unity.c

# > ~ Tests - Char utils

TEST_SRC += $(TEST_DIR)/util/char/test_ms_isdigit.c

test: build
	@echo "🧪 $(YLW)Running tests for $(WNAME)$(GRAY)...$(RES)"
	@$(CC) $(CFLAGS) $(TEST_SRC) $(TEST_INC) -o $(TEST_NAME) -lreadline
	@./$(TEST_NAME)
	@rm -f $(TEST_NAME)

.PHONY: all clean fclean re norm build test
