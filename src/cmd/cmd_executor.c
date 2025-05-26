/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:00:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/05/26 18:10:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*execute_builtins(char *cmd, char *context, char **args)
{
	(void) context;
	if (ms_strequals(cmd, "echo"))
		return (ms_echo(args));
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
	return (execute_builtins(cmd_name, NULL, ms_arrdup(1, args)));
}
