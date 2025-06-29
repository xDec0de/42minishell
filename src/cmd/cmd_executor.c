/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 21:42:21 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fork_and_run(t_shell *shell, char *cmd, char **args, int *exit_code)
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
	char	**input;
	char	*cmd;
	char	**args;
	int		exit_code;

	input = ms_split(token->value, ' ');
	expand_cmd_input(shell, input);
	cmd = ms_strdup(input[0]);
	args = ms_arrdup(1, input);
	ms_arrfree(input);
	if (is_state_builtin(cmd))
		exit_code = execute_state_builtins(shell, cmd, args);
	else
		fork_and_run(shell, cmd, args, &exit_code);
	shell->last_exit_code = exit_code;
	ms_arrfree(args);
	free(cmd);
}
