/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 12:30:41 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 - Modules
 */

# include "ms_utils.h"
# include "cmd/cmd.h"
# include "env/env.h"
# include "expander/expander.h"
# include "parser/parser.h"
# include "signal/ms_signal.h"

/*
 - Libraries
 */

/* PATH_MAX and other limits */
# include <linux/limits.h>

/* bool type */
# include <stdbool.h>

/* readline */
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/* malloc */
# include <stdlib.h>

/* getcwd */
# include <unistd.h>

/* waitpid */
# include <sys/wait.h>

/* errno */
# include <errno.h>

/* open */
# include <fcntl.h>

/* stat, lstat & fstat */
# include <sys/stat.h>

/**
 * @brief Default prompt displayed by minishell.
 */
# define SHELL_PROMPT "minishell: $ "

/**
 * @brief Main minishell struct storing global state.
 *
 * - last_input: Last raw command line entered by the user.
 * - last_tokens: Token list from the last parsed command.
 * - cmd_pid: PID of the last executed command.
 * - last_exit_code: Exit code of the last executed command.
 * - env: Linked list of environment variables.
 * - pwd: Current working directory.
 */
typedef struct s_shell
{
	char	*last_input;
	t_token	*last_tokens;
	pid_t	cmd_pid;
	int		last_exit_code;
	t_env	*env;
	char	*pwd;
}			t_shell;

/**
 * @brief Initializes custom signal handling for the shell.
 *
 * Sets up proper handling for SIGINT and ignores SIGQUIT.
 */
void	init_sighandler(void);

/**
 * @brief Exits the shell, freeing all resources.
 *
 * @param code The exit code to return to the system.
 * @param err Optional error message to print before exiting (can be NULL).
 */
void	ms_exit(int code, char *err);

/**
 * @brief Gets the global shell instance (singleton pattern).
 *
 * @return Pointer to the global t_shell instance.
 */
t_shell	*get_shell(void);

/**
 * @brief Initializes the shell with the given environment variables.
 *
 * @param env The environment variables (from main).
 *
 * @return Pointer to the initialized t_shell struct.
 */
t_shell	*init_shell(char **env);

/*
 - Execution codes
 */

/**
 * @brief Command or program execution was successful.
 */
# define EXEC_OK 0

/**
 * @brief Command or program execution failed (default error code).
 */
# define EXEC_FAIL 1

/**
 * @brief Error code: Malloc failed.
 */
# define MALLOC_ERRN 1

/**
 * @brief Error message: Malloc failed.
 */
# define MALLOC_ERR "Error: Malloc failed\n"

#endif
