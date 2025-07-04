/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:48:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/04 16:05:10 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_cmd_to_args(char *cmd, char	**args)
{
	char	**res;
	t_ulong	res_i;
	t_ulong	args_i;

	res = ms_calloc(ms_arrlen((void **) args) + 2, sizeof(char **));
	res_i = 0;
	res[res_i] = ms_strdup(cmd);
	res_i++;
	args_i = 0;
	while (args[args_i] != NULL)
	{
		res[res_i] = ms_strdup(args[args_i]);
		args_i++;
		res_i++;
	}
	res[res_i] = NULL;
	ms_arrfree(args);
	return (res);
}

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
	token->args = add_cmd_to_args(token->cmd, token->args);
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
