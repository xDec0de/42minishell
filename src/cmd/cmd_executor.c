/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 18:53:34 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <sys/wait.h>

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

void	fork_and_run(t_shell *shell, char *cmd, char **args, int *exit_code)
{
	int		fork_val;

	fork_val = fork();
	if (fork_val == 0)
	{
		execute_fork_builtins(shell, cmd, args);
		execute_external(shell, cmd, args);
	}
	else
	{
		shell->cmd_pid = fork_val;
		waitpid(shell->cmd_pid, exit_code, 0);
		*exit_code = WEXITSTATUS(*exit_code);
	}
}

void	execute_cmd(t_shell *shell, t_token *token)
{
	char	**value;
	char	*cmd;
	char	**args;
	int		exit_code;

	value = ms_split(token->value, ' ');
	expand_input(shell, value);
	cmd = ms_strdup(value[0]);
	args = ms_arrdup(1, value);
	ms_arrfree(value);
	if (is_state_builtin(cmd))
		exit_code = execute_state_builtins(shell, cmd, args);
	else
		fork_and_run(shell, cmd, args, &exit_code);
	shell->last_exit_code = exit_code;
	ms_arrfree(args);
	free(cmd);
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
