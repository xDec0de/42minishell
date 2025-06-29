/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd_executor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:57:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 01:14:54 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_state_builtin(char *cmd)
{
	return (ms_strequals(cmd, "exit") || ms_strequals(cmd, "export")
		|| ms_strequals(cmd, "unset") || ms_strequals(cmd, "cd"));
}

int	execute_state_builtins(t_shell *shell, t_token *token)
{
	if (ms_strequals(token->cmd, "exit"))
		bltn_exit(token->args);
	if (ms_strequals(token->cmd, "export"))
		return (bltn_export(shell, token->args));
	if (ms_strequals(token->cmd, "unset"))
		return (bltn_unset(shell, token->args));
	if (ms_strequals(token->cmd, "cd"))
		return (bltn_cd(shell, token->args));
	return (127);
}

void	execute_fork_builtins(t_shell *shell, t_token *token)
{
	if (ms_strequals(token->cmd, "env"))
		bltn_env(shell);
	if (ms_strequals(token->cmd, "echo"))
		bltn_echo(token->args);
	if (ms_strequals(token->cmd, "pwd"))
		bltn_pwd();
}
