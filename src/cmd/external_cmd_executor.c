/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:48:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 01:16:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_external(t_shell *shell, t_token *token)
{
	int		code;
	char	**env;
	char	*err;

	env = env_to_array(shell);
	code = execve(token->cmd, token->args, env);
	ms_arrfree(env);
	if (code != EXECVE_ERRN)
		ms_exit(code, NULL);
	if (errno == 2)
		err = "command not found";
	else
		err = strerror(errno);
	printf("minishell: %s: %s\n", token->cmd, err);
	exit(127);
}
