/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:50:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 21:21:14 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

struct	s_shell;

/*
 - Command struct
 */

typedef struct s_cmd
{
	int		exit_code;
	char	*output;
	bool	is_builtin;
}			t_cmd;

/*
 - Command functions
 */

t_cmd	*build_cmd(int exit_code, char *output, bool is_builtin);

void	parse_cmd_input(struct s_shell *shell);

/*
 - External command executor
 */

t_cmd	*execute_external(struct s_shell *shell, char *cmd, char **args);

/*
 - Builtins
 */

t_cmd	*bltn_cd(struct s_shell *shell, char **args);

t_cmd	*bltn_echo(char **args);

t_cmd	*bltn_env(struct s_shell *shell);

t_cmd	*bltn_exit(struct s_shell *shell, char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

t_cmd	*bltn_export(struct s_shell *shell, char **args);

t_cmd	*bltn_pwd(void);

t_cmd	*bltn_unset(struct s_shell *shell, char **args);

#endif
