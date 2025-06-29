/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:35:57 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 21:41:29 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_cmd_input(t_shell *shell, char **input)
{
	t_ulong	i;
	char	*tmp;

	i = 0;
	while (input[i] != NULL)
	{
		tmp = expand(shell, input[i]);
		free(input[i]);
		input[i] = tmp;
		i++;
	}
}

void	handle_cmd_input(t_shell *shell)
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
		shell->cmd_pid = 0;
		tmp = tmp->next;
	}
	free_token_list(tokens);
	ms_arrfree(token_arr);
}
