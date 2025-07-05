/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:46:52 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/05 11:11:14 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_free(t_shell	*shell)
{
	if (shell == NULL)
		return ;
	rl_clear_history();
	if (shell->last_input != NULL)
		free(shell->last_input);
	free_token_list(shell->last_tokens);
	env_free(shell);
	if (shell->pwd != NULL)
		free(shell->pwd);
	free(shell);
}

void	ms_exit(int code, char *err)
{
	ms_free(get_shell());
	if (err != NULL)
		printf("%s", err);
	exit(code);
}
