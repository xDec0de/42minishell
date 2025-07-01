/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:48:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/01 16:51:46 by daniema3         ###   ########.fr       */
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
		exit(EC_CMD_NOT_FOUND);
	}
	env = env_to_array(shell);
	execve(path, token->args, env);
	free(path);
	ms_arrfree(env);
	if (errno == EACCES)
	{
		fprintf(stderr, "minishell: %s: Permission denied\n", token->cmd);
		exit(EC_NO_PERM);
	}
	err = strerror(errno);
	fprintf(stderr, "minishell: %s: %s\n", token->cmd, err);
	exit(errno);
}
