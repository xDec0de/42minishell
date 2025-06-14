# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 20:23:54 by daniema3          #+#    #+#              #
#    Updated: 2025/06/14 21:16:33 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

NAME = minishell
TEST_NAME = test_$(NAME)

SRC_DIR = ./src
OBJ_DIR = ./objs

LOG_DIR = ./logs
TEST_DIR = ./test
COV_DIR = $(TEST_DIR)/coverage

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
	@echo -n "\r⏳ $(YLW)Removing $(WNAME) objs$(GRAY)...$(RES)"
	@rm -rf $(OBJ_DIR)
	@echo -n "\r✅ $(GREEN)Removed $(OKNAME) objs$(GRAY).$(RES)"
	@echo 
	@echo -n "\r⏳ $(YLW)Removing $(WNAME) coverage files$(GRAY)...$(RES)"
	@rm -rf $(COV_DIR)
	@rm -rf *.gcda *.gcno
	@echo -n "\r✅ $(GREEN)Removed $(OKNAME) coverage files$(GRAY).$(RES)"
	@echo 
	@echo -n "\r⏳ $(YLW)Removing $(WNAME) logs$(GRAY)...$(RES)"
	@rm -rf $(LOG_DIR)
	@echo -n "\r✅ $(GREEN)Removed $(OKNAME) logs$(GRAY).$(RES)"
	@echo 

fclean: clean
	@echo -n "\r⏳ $(YLW)Removing $(WNAME) executables$(GRAY)...$(RES)"
	@rm -rf $(NAME)
	@rm -rf $(TEST_NAME)
	@echo -n "\r✅ $(GREEN)Removed $(OKNAME) executables$(GRAY).$(RES)"
	@echo 

# > ~ Clean & compile

re: fclean $(NAME)

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
		exit 1; \
	else \
		echo -n "\r✅ $(GREEN)No norm errors found on $(OKNAME)!$(RES)\n"; \
		rm -rf $(NORM_ERRFILE); \
	fi

build:
	@$(MAKE) norm 2>/dev/null || true
	@$(MAKE) re

# > ~ Tests

CFLAGS += -fprofile-arcs -ftest-coverage
TEST_INC = -I$(TEST_DIR)

# > ~ Tests - Char utils

TEST_SRC = util/char/test_ms_isdigit.c

# > ~ Tests - String utils

TEST_SRC +=	util/str/test_ms_strequals.c \
			util/str/test_ms_strlen.c

# > ~ Tests - Add directory prefix

TEST_SRC := $(addprefix $(TEST_DIR)/, $(TEST_SRC))

TEST_SRC +=	$(filter-out $(SRC_DIR)/minishell.c, $(SRCS))

testonly:
	@$(MAKE) fclean
	@mkdir -p $(LOG_DIR)
	@FAILED=0; \
	TESTFILES="$(TEST_SRC)"; \
	for FILE in $$TESTFILES; do \
		BASENAME=$$(basename $$FILE .c); \
		if echo $$BASENAME | grep -q "^test_"; then \
			EXEC="./$(LOG_DIR)/$$BASENAME.bin"; \
			LOG="./$(LOG_DIR)/$$BASENAME.valgrind"; \
			ERR="./$(LOG_DIR)/$$BASENAME.stderr"; \
			SRCS="$$FILE $(filter-out $(SRC_DIR)/minishell.c, $(SRCS))"; \
			COMPILE_OUTPUT=$$( $(CC) $(CFLAGS) $$SRCS $(TEST_INC) -o $$EXEC -lreadline 2>&1 ); \
			if [ $$? -ne 0 ]; then \
				printf "❌ $(RED)Failed to compile test $(BRED)%s$(GRAY):$(RES)\n" "$$BASENAME"; \
				echo "$$COMPILE_OUTPUT"; \
				FAILED=$$((FAILED + 1)); \
				continue; \
			fi; \
			valgrind --leak-check=full --error-exitcode=123 --log-file="$$LOG" $$EXEC 2> $$ERR; \
			STATUS=$$?; \
			if [ $$STATUS -eq 0 ]; then \
				printf "✅ $(GREEN)%s passed$(RES)\n" "$$BASENAME"; \
			elif [ $$STATUS -eq 123 ]; then \
				printf "⚠️  $(BYLW)%s passed but has memory leaks$(RES)\n" "$$BASENAME"; \
				FAILED=$$((FAILED + 1)); \
			elif [ $$STATUS -gt 0 ] && [ $$STATUS -lt 128 ]; then \
				printf "❌ $(RED)%s failed test #%d$(GRAY):$(RED) " "$$BASENAME" "$$STATUS"; \
				cat $$ERR; \
				printf "$(RES)\n"; \
				FAILED=$$((FAILED + 1)); \
			else \
				SIGNAL=$$(( $$STATUS - 128 )); \
				printf "💥 $(BRED)%s crashed with signal %d$(RES)\n" "$$BASENAME" "$$SIGNAL"; \
				FAILED=$$((FAILED + 1)); \
			fi; \
			rm -f $$ERR; \
		fi; \
	done; \
	if [ $$FAILED -eq 0 ]; then \
		echo "$(GREEN)✅ All tests passed!$(RES)"; \
	else \
		echo "$(RED)❌ $$FAILED test(s) failed.$(RES)"; \
		exit 1; \
	fi
	@rm -rf logs/*.bin

test:
	@$(MAKE) norm
	@$(MAKE) testonly 2>/dev/null
	@rm -rf logs/*.gcda logs/*.gcno

testcov:
	@$(MAKE) build
	@$(MAKE) testonly 2>/dev/null
	@$(MAKE) covonly

COV_INFO = $(COV_DIR)/coverage.info
COV_EXCLUDE = '/usr/*' '*/test/*'

covonly:
	@mkdir -p $(COV_DIR)
	@if command -v lcov >/dev/null 2>&1; then \
		echo -n "\r⏳ $(YLW)Generating coverage report$(GRAY)...$(RES)"; \
		lcov --capture --directory . --output-file $(COV_INFO) >/dev/null 2>&1; \
		lcov --remove $(COV_INFO) $(COV_EXCLUDE) --output-file $(COV_INFO) >/dev/null 2>&1; \
		genhtml $(COV_INFO) --output-directory $(COV_DIR) >/dev/null 2>&1; \
		echo -n "\r✅ $(GREEN)Coverage reports generated at $(COV_DIR)$(RES)\n"; \
	else \
		echo -n "\r❌ $(RED)Install lcov for coverage reports.$(RES)\n"; \
	fi
	@rm -rf *.gcda *.gcno

.PHONY: all clean fclean re norm build testonly test testcov covonly
