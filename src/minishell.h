/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 01:19:19 by daniema3         ###   ########.fr       */
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

# define SHELL_PROMPT "minishell: $ "

/*
 - Minishell struct
 */

typedef struct s_shell
{
	char	*last_input;
	t_token	*last_tokens;
	pid_t	cmd_pid;
	int		last_exit_code;
	t_env	*env;
}			t_shell;

/*
 - Signal
 */

void	init_sighandler(void);

/*
 - Shell instance
 */

void	ms_exit(int code, char *err);

t_shell	*get_shell(void);

t_shell	*init_shell(char **env);

/*
 - Execution codes
 */

/** Command or program execution was successful. */
# define EXEC_OK 0

/** Command or program execution failed (Default). */
# define EXEC_FAIL 1

/*
 - Internal error codes
 */

# define MALLOC_ERRN 1
# define MALLOC_ERR "Error: Malloc failed\n"

#endif
