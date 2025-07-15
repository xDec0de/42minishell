/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/15 20:34:48 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fork_and_run(t_shell *shell, t_token *token, int *exit_code)
{
	int		fork_val;

	fork_val = fork();
	if (fork_val == 0)
	{
		execute_fork_builtins(shell, token);
		execute_external(shell, token);
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
	int		exit_code;

	if (token->cmd == NULL)
		return ;
	expand_token(shell, token);
	if (is_state_builtin(token->cmd))
		exit_code = execute_state_builtins(shell, token);
	else
		fork_and_run(shell, token, &exit_code);
	shell->last_exit_code = exit_code;
}
