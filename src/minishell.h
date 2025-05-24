/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/05/24 21:58:41 by daniema3         ###   ########.fr       */
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

typedef struct s_shell
{
	bool	running;
	char	*last_input;
}			t_shell;

typedef struct s_cmd
{
	int		exit_code;
	char	*output;
}			t_cmd;

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
 - String utils
 */

size_t	ms_strlen(char *str);

bool	ms_strequals(char *str, char *other);

/*
 - Error codes
 */

# define MALLOC_ERRN 1
# define MALLOC_ERR "Error: Malloc failed\n"

#endif
