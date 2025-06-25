/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:50:33 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/26 01:14:25 by rexposit         ###   ########.fr       */
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
}			t_cmd;

/*
 - Command functions
 */

t_cmd	*build_cmd(int exit_code, char *output);

void	parse_cmd_input(struct s_shell *shell);

/*
 - Builtins
 */

t_cmd	*bltn_cd(char **args);

t_cmd	*bltn_echo(char **args);

t_cmd	*bltn_env(struct s_shell *shell);

t_cmd	*bltn_exit(struct s_shell *shell, char **args);

# define EXIT_NOT_NUMERIC_ERRN 2
# define EXIT_NOT_NUMERIC "bash: exit: %s: numeric argument required\n"

t_cmd	*bltn_export(struct s_shell *shell, char **args);

t_cmd	*bltn_pwd(void);

t_cmd	*bltn_unset(struct s_shell *shell, char **args);

#endif
