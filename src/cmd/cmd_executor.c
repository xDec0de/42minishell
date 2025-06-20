/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/20 21:14:12 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_last_output(t_shell *shell)
{
	if (shell->last_cmd == NULL)
		return (NULL);
	return (shell->last_cmd->output);
}

t_cmd	*execute_builtins(t_shell *shell, char *cmd, char **args)
{
	if (ms_strequals(cmd, "exit"))
		return (bltn_exit(shell, args));
	if (ms_strequals(cmd, "env"))
		return (bltn_env(shell));
	if (ms_strequals(cmd, "echo"))
		return (bltn_echo(args));
	if (ms_strequals(cmd, "export"))
		return (bltn_export(shell, args));
	return (NULL);
}

/*
 - Temporary parser for builtin testing
*/

t_cmd	*parse_cmd_input(t_shell *shell)
{
	t_cmd	*cmd;
	char	*cmd_name;
	char	**args;
	char	**cmd_args;

	args = ms_split(shell->last_input, ' ');
	cmd_args = ms_arrdup(1, args);
	cmd_name = args[0];
	cmd = execute_builtins(shell, cmd_name, ms_arrdup(1, args));
	ms_arrfree(args);
	ms_arrfree(cmd_args);
	return (cmd);
}
