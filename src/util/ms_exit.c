/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:46:52 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 13:24:51 by daniema3         ###   ########.fr       */
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
	if (shell->last_cmd != NULL)
	{
		if (shell->last_cmd->output != NULL)
			free(shell->last_cmd->output);
		free(shell->last_cmd);
	}
	env_free(shell);
	free(shell);
}

void	ms_exit(int code, char *err)
{
	ms_free(get_shell());
	if (err != NULL)
		printf("%s", err);
	exit(code);
}
