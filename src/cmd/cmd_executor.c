/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 19:25:28 by rexposit         ###   ########.fr       */
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
	if (ms_strequals(cmd, "pwd"))
		return (bltn_pwd());
	if (ms_strequals(cmd, "unset"))
		return (bltn_unset(shell, args));
	return (NULL);
}

t_cmd	*execute_cmd(t_shell *shell, t_token *token)
{
	t_cmd	*cmd;
	char	**value;
	char	**cmd_args;

	value = ms_split(token->value, ' ');
	cmd_args = ms_arrdup(1, value);
	cmd = execute_builtins(shell, value[0], cmd_args);
	ms_arrfree(cmd_args);
	ms_arrfree(value);
	return (cmd);
}

void	parse_cmd_input(t_shell *shell)
{
	char	**token_arr;
	t_token	*tokens;
	t_token	*tmp;

	token_arr = to_token_array(shell->last_input);
	tokens = tokenize(token_arr);
	tmp = tokens;
	while (tmp != NULL)
	{
		if (shell->last_cmd != NULL && shell->last_cmd->output != NULL)
			free(shell->last_cmd->output);
		shell->last_cmd = execute_cmd(shell, tmp);
		tmp = tmp->next;
	}
	free_token_list(tokens);
	ms_arrfree(token_arr);
}
