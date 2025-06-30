/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:48:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 15:40:09 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_external(t_shell *shell, t_token *token)
{
	char	**env;
	char	*path;
	char	*err;

	path = get_cmd_from_path(shell, token->cmd);
	if (path == NULL)
	{
		fprintf(stderr, "minishell: %s: command not found\n", token->cmd);
		exit(127);
	}
	env = env_to_array(shell);
	execve(path, token->args, env);
	ms_arrfree(env);
	if (errno == EACCES)
		exit(126);
	err = strerror(errno);
	fprintf(stderr, "minishell: %s: %s\n", token->cmd, err);
	exit(127);
}
