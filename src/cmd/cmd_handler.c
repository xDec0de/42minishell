/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:35:57 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/18 20:23:56 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*prepare_tokens(t_shell *shell)
{
	char		**token_arr;
	t_token		*tokens;

	if (!validate_input(shell->last_input))
		return (NULL);
	token_arr = to_token_array(shell->last_input);
	tokens = tokenize(token_arr);
	ms_arrfree(token_arr);
	return (tokens);
}

void	handle_cmd_input(t_shell *shell)
{
	int	og_stdin;
	int	og_stdout;

	shell->last_tokens = prepare_tokens(shell);
	if (shell->last_tokens == NULL)
		return ;
	og_stdin = dup(FD_IN);
	og_stdout = dup(FD_OUT);
	execute_cmd(shell, shell->last_tokens);
	dup2(og_stdin, FD_IN);
	dup2(og_stdout, FD_OUT);
	close(og_stdin);
	close(og_stdout);
	free_token_list(shell->last_tokens);
	shell->last_tokens = NULL;
}
