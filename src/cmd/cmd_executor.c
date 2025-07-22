/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/18 23:42:58 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(t_shell *shell, t_token *token, int *pipefd)
{
	if (!setup_redirections(token))
		ms_exit(EXEC_FAIL, NULL);
	if (token->type == T_PIPE)
	{
		close(pipefd[FD_IN]);
		if (dup2(pipefd[FD_OUT], FD_OUT) == -1)
			ms_exit(EXEC_FAIL, NULL);
		close(pipefd[FD_OUT]);
	}
	execute_fork_builtins(shell, token);
	execute_external(shell, token);
	ms_exit(EXEC_OK, NULL);
}

static void	parent_process(t_shell *shell, t_token *token, int *ec, int *pipefd)
{
	waitpid(shell->cmd_pid, ec, 0);
	*ec = WEXITSTATUS(*ec);
	if (token->type == T_PIPE)
	{
		close(pipefd[FD_OUT]);
		dup2(pipefd[FD_IN], FD_IN);
		close(pipefd[FD_IN]);
		execute_tokens(shell, token->next);
	}
}

static void	fork_and_run(t_shell *shell, t_token *token, int *exit_code)
{
	int		pipefd[2];
	pid_t	pid;

	if (token->type == T_PIPE && pipe(pipefd) == -1)
		return ((void)(*exit_code = 1));
	pid = fork();
	if (pid == 0)
		child_process(shell, token, pipefd);
	else if (pid > 0)
	{
		shell->cmd_pid = pid;
		parent_process(shell, token, exit_code, pipefd);
	}
	else
		*exit_code = 1;
}

void	fill_redirections(t_token *tokens)
{
	t_token	*token;

	token = tokens;
	while (token != NULL && token->next != NULL)
	{
                if (token->type == T_REDIR_IN)
                        token->infile = ms_strdup(token->next->cmd);
                else if (token->type == T_HEREDOC)
                        token->infile = create_heredoc(token->next->cmd);
                else if (token->type == T_REDIR_OUT || token->type == T_REDIR_APPEND)
                        token->outfile = ms_strdup(token->next->cmd);
		token = token->next;
	}
}

void	execute_tokens(t_shell *shell, t_token *token)
{
	int	exit_code;

	if (token == NULL || token->cmd == NULL)
		return ;
	expand_token(shell, token);
	fill_redirections(token);
	clean_tokens(token);
	if (is_state_builtin(token->cmd))
		exit_code = execute_state_builtins(shell, token);
	else
		fork_and_run(shell, token, &exit_code);
	shell->last_exit_code = exit_code;
}
