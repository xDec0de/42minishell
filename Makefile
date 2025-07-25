# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 20:23:54 by daniema3          #+#    #+#              #
#    Updated: 2025/07/25 12:28:01 by daniema3         ###   ########.fr        #
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

INCLUDE_DIRS =	-I$(SRC_DIR) -I$(SRC_DIR)/util -I$(SRC_DIR)/util/array \
				-I$(SRC_DIR)/util/char -I$(SRC_DIR)/util/mem \
				-I$(SRC_DIR)/util/str

CFLAGS = -Wall -Werror -Wextra -g3 -fdiagnostics-color=always $(INCLUDE_DIRS)

# > ~ Main project files

SRCS =	minishell.c

# > ~ Commands

SRCS += cmd/builtin_cmd_executor.c \
		cmd/cmd_executor.c \
		cmd/cmd_handler.c \
		cmd/external_cmd_executor.c \
		cmd/find_path.c \
		cmd/redirections.c

# > ~ Commands - Builtins

SRCS += cmd/builtin/cd.c \
		cmd/builtin/echo.c \
		cmd/builtin/env.c \
		cmd/builtin/exit.c \
		cmd/builtin/export.c \
		cmd/builtin/pwd.c \
		cmd/builtin/unset.c

# > ~ Env

SRCS +=	env/env_export.c \
		env/env_free.c \
		env/env_get.c \
		env/env_init.c \
		env/env_size.c \
		env/env_to_array.c \
		env/env_unset.c

# > ~ Expander

SRCS +=	expander/expander.c

# > ~ Parser

SRCS +=	parser/input_splitter.c \
		parser/input_validator.c \
		parser/token_cleaner.c \
		parser/tokenizer.c

# > ~ Signal

SRCS +=	signal/signal_handler.c

# > ~ Util

SRCS +=	util/ms_exit.c \
		util/ms_print.c \
		util/shell_getter.c

# > ~ Array utils

SRCS +=	util/array/ms_arradd.c \
		util/array/ms_arrdup.c \
		util/array/ms_arrfree.c \
		util/array/ms_arrlen.c

# > ~ Char utils

SRCS += util/char/ms_isdigit.c \
		util/char/ms_isenvkeychar.c \
		util/char/ms_isquote.c \
		util/char/ms_isspace.c \
		util/char/ms_isspecial.c

# > ~ Memory utils

SRCS +=	util/mem/ms_bzero.c \
		util/mem/ms_calloc.c \
		util/mem/ms_malloc.c

# > ~ String utils

SRCS +=	util/str/ms_atoi.c \
		util/str/ms_itoa.c \
		util/str/ms_split.c \
		util/str/ms_strchr.c \
		util/str/ms_strdup.c \
		util/str/ms_strequals.c \
		util/str/ms_strindexof.c \
		util/str/ms_strisnumeric.c \
		util/str/ms_strjoin.c \
		util/str/ms_strlcpy.c \
		util/str/ms_strlen.c \
		util/str/ms_strncmp.c \
		util/str/ms_strremchar.c \
		util/str/ms_strreplace.c \
		util/str/ms_substr.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# > ~ Colors!

RED = \033[0;31m
BRED = \033[1;31m
GREEN = \033[0;32m
BGREEN = \033[1;32m
YLW = \033[0;33m
BYLW = \033[1;33m
BLUE = \033[0;36m
BBLUE = \033[1;36m
GRAY = \033[0;30m
RES = \033[0m                                                                   

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
	@norminette $(SRC_DIR) | grep "Error" > $(NORM_ERRFILE) || true
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

# > ~ Valgrind check

VG_LOG = ./logs/valgrind.log

valgrind:
	@mkdir -p $(LOG_DIR)
	@valgrind --leak-check=full --show-leak-kinds=all --log-file=$(VG_LOG) ./$(NAME)
	@awk ' \
		/^==[0-9]+== [0-9,]+ bytes in/ { \
			if (bytes) { \
				if (is_readline) readline_total += bytes; \
				else program_total += bytes; \
			} \
			line = $$0; \
			sub(/^==[0-9]+== /, "", line); \
			sub(/ bytes.*/, "", line); \
			gsub(/,/, "", line); \
			bytes = line + 0; \
			is_readline = 0; \
			next; \
		} \
		/libreadline\.so/ { is_readline = 1; next; } \
		END { \
			if (bytes) { \
				if (is_readline) readline_total += bytes; \
				else program_total += bytes; \
			} \
			printf "$(BLUE)Original valgrind log saved at$(GRAY): $(BBLUE)$(VG_LOG)\n"; \
			if (readline_total > 0) \
				printf("$(YLW)Readline leaks$(GRAY): $(BYLW)%d bytes$(RES)\n", readline_total); \
			else \
				printf("$(GREEN)Readline leaks$(GRAY): $(BGREEN)0 bytes$(RES)\n"); \
			if (program_total > 0) { \
				printf("$(RED)$(NAME) leaks$(GRAY): $(BRED)%d bytes$(RES)\n", program_total); \
				exit 1; \
			} else { \
				printf("$(GREEN)$(NAME) leaks$(GRAY): $(BGREEN)0 bytes$(RES)\n"); \
			} \
		}' $(VG_LOG)

# > ~ Tests

CFLAGS += -fprofile-arcs -ftest-coverage
TEST_INC = -I$(TEST_DIR)

TESTS ?= *
TEST_SRC := $(shell find $(TEST_DIR) -type f -name '$(TESTS).c')
CORE_OBJS := $(filter-out $(OBJ_DIR)/minishell.o, $(OBJS))

testonly:
	@$(MAKE) | grep -q "Nothing to be done" || true
	@mkdir -p $(LOG_DIR)
	@FAILED=0; \
	TESTFILES="$(TEST_SRC)"; \
	for FILE in $$TESTFILES; do \
		BASENAME=$$(basename $$FILE .c); \
		if echo $$BASENAME | grep -q "^test_"; then \
			EXEC="./$(LOG_DIR)/$$BASENAME.bin"; \
			LOG="./$(LOG_DIR)/$$BASENAME.valgrind"; \
			ERR="./$(LOG_DIR)/$$BASENAME.stderr"; \
			COMPILE_OUTPUT=$$($(CC) $(CFLAGS) $$FILE $(CORE_OBJS) -o $$EXEC $(TEST_INC) -lreadline 2>&1); \
			if [ $$? -ne 0 ]; then \
				printf "❌ $(RED)Failed to compile test $(BRED)%s$(GRAY):$(RES)\n" "$$BASENAME"; \
				echo "$$COMPILE_OUTPUT"; \
				FAILED=$$((FAILED + 1)); \
				continue; \
			fi; \
			if echo "$$BASENAME" | grep -q "_vg$$"; then \
				valgrind --leak-check=full --error-exitcode=123 --log-file="$$LOG" $$EXEC 2> $$ERR; \
			else \
				$$EXEC 2> $$ERR; \
			fi; \
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
	rm -rf $(LOG_DIR)/*.bin; \
	if [ $$FAILED -eq 0 ]; then \
		echo "$(GREEN)✅ All tests passed!$(RES)"; \
	else \
		echo "$(RED)❌ $$FAILED test(s) failed.$(RES)"; \
		exit 1; \
	fi

test:
	@$(MAKE) norm
	@$(MAKE) testonly; TEST_RESULT=$$?; \
	rm -f $(LOG_DIR)/*.gcda $(LOG_DIR)/*.gcno; \
	exit $$TEST_RESULT

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

.PHONY: all clean fclean re norm build valgrind testonly test testcov covonly
