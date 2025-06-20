/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/21 01:10:18 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 - Modules
 */

# include "env/env.h"
# include "parser/parser.h"

/*
 - Libraries
 */

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
	t_env	*env;
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

t_cmd	*bltn_env(t_shell *shell);

t_cmd	*bltn_exit(t_shell *shell, char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

t_cmd	*bltn_export(t_shell *shell, char **args);

t_cmd	*bltn_unset(t_shell *shell, char **args);

/*
 - Signal
 */

void	init_sighandler(void);

/*
 - Util
 */

void	ms_exit(int code, char *err);

t_shell	*get_shell(void);

t_shell	*init_shell(char **env);

/*
 - Array utils
 */

/**
 * @brief Returns a `NULL` terminated array duplicate
 * of the provided `arr`, starting at the `from` index.
 * Strings inside the array are also duplicated with
 * `ms_strdup`
 * 
 * @param from The index at which the duplication will start.
 * @param arr The array to duplicated. It is expected
 * that this array is `NULL` terminated, the behaviour
 * is undefined otherwise.
 * 
 * @return A duplicate of `arr`, from `from` to its end.
 * `NULL` if `from` is bigger than the length of `arr`, or
 * if `arr` itself is `NULL`.
 */
char	**ms_arrdup(size_t from, char **arr);

/**
 * @brief Frees the provided `arr` and all of its contents.
 * 
 * @param arr The array to free. It is expected
 * that this array is `NULL` terminated, the behaviour
 * is undefined otherwise.
 */
void	ms_arrfree(char **arr);

size_t	ms_arrlen(void **arr);

/*
 - Char utils
 */

bool	ms_isdigit(char ch);

bool	ms_isquote(char c);

bool	ms_isspace(char ch);

/*
 - Memory utils
 */

void	ms_bzero(void	*str, size_t n);

void	*ms_calloc(size_t amount, size_t size);

void	*ms_malloc(size_t	size);

/*
 - String utils
 */

int		ms_atoi(const char *str);

char	**ms_split(const char *s, char c);

char	*ms_strchr(const char *s, int c);

char	*ms_strdup(const char *str);

bool	ms_strequals(char *str, char *other);

bool	ms_strisnumeric(const char *str, bool allow_spaces);

size_t	ms_strlcpy(char *dest, const char *src, size_t dstsize);

size_t	ms_strlen(const char *str);

char	*ms_strreplace(char *str, size_t from, size_t size, char *replacement);

char	*ms_substr(const char *str, unsigned int start, size_t len);

/** Command or program execution was successful. */
# define EXEC_OK 0

/*
 - Internal error codes
 */

# define MALLOC_ERRN 1
# define MALLOC_ERR "Error: Malloc failed\n"

#endif
