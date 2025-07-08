/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:35:57 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 12:59:44 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cmd_input(t_shell *shell)
{
	char	**token_arr;
	t_token	*tmp;

	if (!validate_input(shell->last_input))
		return ;
	token_arr = to_token_array(shell->last_input);
	shell->last_tokens = tokenize(token_arr);
	ms_arrfree(token_arr);
	tmp = shell->last_tokens;
	while (tmp != NULL)
	{
		execute_cmd(shell, tmp);
		shell->cmd_pid = 0;
		tmp = tmp->next;
	}
	free_token_list(shell->last_tokens);
	shell->last_tokens = NULL;
}
