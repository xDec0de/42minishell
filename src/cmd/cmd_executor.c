/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 16:18:44 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>

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
	if (ms_strequals(cmd, "cd"))
		return (bltn_cd(shell, args));
	return (NULL);
}

void	expand_input(t_shell *shell, char **value)
{
	t_ulong	i;
	char	*tmp;

	i = 0;
	while (value[i] != NULL)
	{
		tmp = expand(shell, value[i]);
		free(value[i]);
		value[i] = tmp;
		i++;
	}
}

void	execute_cmd(t_shell *shell, t_token *token)
{
	t_cmd	*cmd;
	char	**value;
	char	**cmd_args;

	value = ms_split(token->value, ' ');
	expand_input(shell, value);
	cmd_args = ms_arrdup(1, value);
	cmd = execute_builtins(shell, value[0], cmd_args);
	if (cmd == NULL)
		cmd = execute_external(shell, value[0], cmd_args);
	shell->last_cmd = cmd;
	ms_arrfree(cmd_args);
	ms_arrfree(value);
	if (cmd == NULL)
		exit(127);
	if (cmd->is_builtin)
		exit(cmd->exit_code);
}

void	parse_cmd_input(t_shell *shell)
{
	char	**token_arr;
	t_token	*tokens;
	t_token	*tmp;
	int		fork_val;

	token_arr = to_token_array(shell->last_input);
	tokens = tokenize(token_arr);
	tmp = tokens;
	while (tmp != NULL)
	{
		if (shell->last_cmd != NULL && shell->last_cmd->output != NULL)
			free(shell->last_cmd->output);
		fork_val = fork();
		if (fork_val == 0)
			execute_cmd(shell, tmp);
		else
		{
			shell->cmd_pid = fork_val;
			waitpid(shell->cmd_pid, NULL, 0);
			tmp = tmp->next;
		}
	}
	free_token_list(tokens);
	ms_arrfree(token_arr);
}
