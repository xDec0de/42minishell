/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:28:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
 - Modules
 */

# include "util/ms_util.h"
# include "cmd/cmd.h"
# include "env/env.h"
# include "parser/parser.h"

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

/* signal */
# include <signal.h>

/* getcwd */

# include <unistd.h>

# define SHELL_PROMPT "minishell: $ "

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
