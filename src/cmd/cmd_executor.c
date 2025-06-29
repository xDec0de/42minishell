/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 17:52:33 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>

void	execute_builtins(t_shell *shell, char *cmd, char **args)
{
	if (ms_strequals(cmd, "exit"))
		bltn_exit(args);
	if (ms_strequals(cmd, "env"))
		bltn_env(shell);
	if (ms_strequals(cmd, "echo"))
		bltn_echo(args);
	if (ms_strequals(cmd, "export"))
		bltn_export(shell, args);
	if (ms_strequals(cmd, "pwd"))
		bltn_pwd();
	if (ms_strequals(cmd, "unset"))
		bltn_unset(shell, args);
	if (ms_strequals(cmd, "cd"))
		bltn_cd(shell, args);
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
	char	**value;
	char	**cmd_args;
	int		fork_val;

	value = ms_split(token->value, ' ');
	expand_input(shell, value);
	cmd_args = ms_arrdup(1, value);
	fork_val = fork();
	if (fork_val == 0)
	{
		execute_builtins(shell, value[0], cmd_args);
		execute_external(shell, value[0], cmd_args);
	}
	else
	{
		shell->cmd_pid = fork_val;
		waitpid(shell->cmd_pid, &shell->last_exit_code, 0);
		shell->last_exit_code = WEXITSTATUS(shell->last_exit_code);
	}
	ms_arrfree(cmd_args);
	ms_arrfree(value);
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
		execute_cmd(shell, tmp);
		tmp = tmp->next;
	}
	free_token_list(tokens);
	ms_arrfree(token_arr);
}
