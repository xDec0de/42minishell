/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd_executor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:57:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 18:48:19 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_state_builtin(char *cmd)
{
	return (ms_strequals(cmd, "exit") || ms_strequals(cmd, "export")
		|| ms_strequals(cmd, "unset") || ms_strequals(cmd, "cd"));
}

int	execute_state_builtins(t_shell *shell, char *cmd, char **args)
{
	if (ms_strequals(cmd, "exit"))
	{
		free(cmd);
		bltn_exit(args);
		return (0);
	}
	if (ms_strequals(cmd, "export"))
		return (bltn_export(shell, args));
	if (ms_strequals(cmd, "unset"))
		return (bltn_unset(shell, args));
	if (ms_strequals(cmd, "cd"))
		return (bltn_cd(shell, args));
	return (127);
}

void	execute_fork_builtins(t_shell *shell, char *cmd, char **args)
{
	if (ms_strequals(cmd, "env"))
		bltn_env(shell, cmd, args);
	if (ms_strequals(cmd, "echo"))
		bltn_echo(cmd, args);
	if (ms_strequals(cmd, "pwd"))
		bltn_pwd(cmd, args);
}
