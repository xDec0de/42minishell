/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/11 18:08:25 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_shell	*shell;

	shell = init_shell();
	init_sighandler();
	while (shell->running)
	{
		if (shell->last_input != NULL)
			free(shell->last_input);
		shell->last_input = readline("minishell: ");
		if (shell->last_input == NULL)
			ms_exit(EXEC_OK, NULL);
		shell->last_cmd = parse_cmd_input(shell);
		add_history(shell->last_input);
	}
	if (shell->last_cmd != NULL)
		return (shell->last_cmd->exit_code);
	return (EXEC_OK);
}
