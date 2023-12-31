# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iortego- <iortego-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 18:43:24 by iortego-          #+#    #+#              #
#    Updated: 2023/11/17 17:30:16 by iortego-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell

CC  = gcc
AR = ar
ARFLAGS = -rc
RM = rm -rf 
OBJDIR = build
SRCDIR = src
INCDIR = include


LDFLAGS += -lreadline -L $(LFTPATH) -l$(LFTNAME)
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)
LFTPATH = libft
LFTNAME = ft
LFT = $(LFTPATH)/lib$(LFTNAME).a
CFLAGS += -I $(LFTPATH)/include

SRCS = minishell.c

# SRCS += \
# 		builtins/echo.c \
# 		builtins/exit.c \
# 		builtins/pwd.c \
# 		builtins/env.c

# SRCS += \
# 		parser/lexer.c

SRCS += parser/*.c builtins/*.c

OBJS := $(addprefix $(OBJDIR)/,$(SRCS:%.c=%.o))

all: $(NAME)

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: $(OBJS) $(LFTNAME)sanitize banner
	@echo "[$(NAME)]->>\033[34m [◊] SANITIZE MODE ON [◊]\033[0m"
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

debug: CFLAGS += -g3
debug: $(OBJS) $(LFTNAME)debug banner
	@echo "[$(NAME)]->>\033[33m [∆] DEBUG MODE ON [∆]\033[0m"
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

banner:
	@echo "\033[1;33m [!] WARNING [!]\033[0m\n\tWildcards are enabled\n\n\n"
$(NAME): banner $(OBJS) $(LFT) banner
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

$(LFTNAME)debug:
	make -C $(LFTPATH) debug

$(LFTNAME)sanitize:
	make -C $(LFTPATH) sanitize

$(LFT):
	make -C $(LFTPATH)

$(OBJDIR):
	mkdir build
	mkdir build/builtins
	mkdir build/parser

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make fclean -C $(LFTPATH)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

red: fclean debug

res: fclean sanitize

.PHONY: sanitize debug res red re clean fclean all
