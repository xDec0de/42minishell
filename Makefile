# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 20:23:54 by daniema3          #+#    #+#              #
#    Updated: 2025/06/12 16:31:15 by daniema3         ###   ########.fr        #
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

LOG_DIR = ./logs
NORM_ERRFILE = $(LOG_DIR)/norm_errors.txt

# > ~ Norminette check

norm:
	@mkdir -p $(LOG_DIR)
	@rm -rf $(NORM_ERRFILE)
	@echo -n "\r⏳ $(YLW)Executing norminette on $(WNAME)$(GRAY)...$(RES)"
	@norminette $(SRC_DIR) | grep "Error:" > $(NORM_ERRFILE) || true
	@if [ -s $(NORM_ERRFILE) ]; then \
		echo -n "\r❌ $(RED)Norm errors found on $(ERRNAME)$(GRAY):$(RES)\n";\
		cat $(NORM_ERRFILE) | sed 's/^Error:/-/'; \
	else \
		echo -n "\r✅ $(GREEN)No norm errors found on $(OKNAME)!$(RES)\n"; \
		rm -rf $(NORM_ERRFILE); \
	fi

build: norm re

# > ~ Tests

TEST_NAME = test_$(NAME)

TEST_DIR = ./test
UNITY_DIR = $(TEST_DIR)/unity

TEST_INC = -I$(UNITY_DIR)/src -I$(TEST_DIR)

TEST_SRC =	$(filter-out $(SRC_DIR)/minishell.c, $(SRCS)) \
			$(TEST_DIR)/test_minishell.c \
			$(UNITY_DIR)/src/unity.c

TEST_LOGFILE = $(LOG_DIR)/tests.txt

# > ~ Tests - Char utils

TEST_SRC += $(TEST_DIR)/util/char/test_ms_isdigit.c

testonly:
	@mkdir -p $(LOG_DIR)
	@rm -f $(TEST_NAME) $(TEST_LOGFILE)
	@echo -n "\r⏳ $(YLW)Running tests for $(WNAME)$(GRAY)...$(RES)"
	@$(CC) $(CFLAGS) $(TEST_SRC) $(TEST_INC) \
		-o $(TEST_NAME) -lreadline
	@./$(TEST_NAME) > $(TEST_LOGFILE) 2>&1; \
	echo -n "\r"; \
	TESTS=$$(grep -oP 'test_\w+(?=:PASS|:FAIL)' $(TEST_LOGFILE)); \
	FAILED=0; \
	for t in $$TESTS; do \
		if grep -q "$$t.*:PASS" $(TEST_LOGFILE); then \
			echo "✅ $(GREEN)Test $${t#test_}$(RES)"; \
		else \
			LINE=$$(grep "$$t" $(TEST_LOGFILE) | grep -v ":PASS"); \
			NUM=$$(echo $$LINE | grep -oP 'FAIL: \K[0-9]+'); \
			NAME=$${t#test_}; \
			printf "❌ $(RED)Test $(BRED)%s$(GRAY): " "$$NAME"; \
			printf "$(RED)Failed test $(BRED)%s$(RES)\n" "$$NUM"; \
			FAILED=$$((FAILED + 1)); \
		fi; \
	done; \
	if [ $$FAILED -eq 0 ]; then \
		echo "$(GREEN)✅ All tests have passed!$(RES)"; \
	else \
		echo "$(RED)❌ $$FAILED test(s) failed.$(RES)"; \
	fi

test: build testonly

.PHONY: all clean fclean re norm build test
