/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/11 17:40:03 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* bool type */
# include <stdbool.h>

/* readline */
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/* malloc */
# include <stdlib.h>

/* signal */
# include <signal.h>

/*
 - Command struct
 */

typedef struct s_cmd
{
	int		exit_code;
	char	*output;
}			t_cmd;

/*
 - Minishell struct
 */

typedef struct s_shell
{
	bool	running;
	char	*last_input;
	t_cmd	*last_cmd;
}			t_shell;

/*
 - Command functions
 */

t_cmd	*build_cmd(int exit_code, char *output);

t_cmd	*parse_cmd_input(t_shell *shell);

/*
 - Builtins
 */

t_cmd	*bltn_echo(char **args);

t_cmd	*bltn_exit(t_shell *shell, char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

/*
 - Signal
 */

void	init_sighandler(void);

/*
 - Util
 */

void	ms_exit(int code, char *err);

void	*ms_malloc(size_t	size);

t_shell	*get_shell(void);

t_shell	*init_shell(void);

/*
 - Array utils
 */

char	**ms_arrdup(size_t from, char **arr);

size_t	ms_arrlen(void **arr);

/*
 - Char utils
 */

bool	ms_isdigit(char ch);

/*
 - String utils
 */

int		ms_atoi(const char *str, bool allow_spaces, int def);

char	**ms_split(const char *s, char c);

char	*ms_strdup(const char *str);

bool	ms_strequals(char *str, char *other);

size_t	ms_strlen(char *str);

/** Command or program execution was successful. */
# define EXEC_OK 0

/*
 - Internal error codes
 */

# define MALLOC_ERRN 1
# define MALLOC_ERR "Error: Malloc failed\n"

#endif
