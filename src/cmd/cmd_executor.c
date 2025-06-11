/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/11 17:45:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*execute_builtins(t_shell *shell, char *cmd, char *context, char **args)
{
	(void) context;
	if (ms_strequals(cmd, "exit"))
		return (bltn_exit(shell, args));
	if (ms_strequals(cmd, "echo"))
		return (bltn_echo(args));
	return (NULL);
}

/*
 - Temporary parser for builtin testing
*/

t_cmd	*parse_cmd_input(t_shell *shell)
{
	char	*cmd_name;
	char	**args;

	args = ms_split(shell->last_input, ' ');
	cmd_name = args[0];
	return (execute_builtins(shell, cmd_name, NULL, ms_arrdup(1, args)));
}
