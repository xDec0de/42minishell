/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:48:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 17:49:37 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

void	execute_external(t_shell *shell, char *cmd, char **args)
{
	int		code;
	char	**env;
	char	*err;

	env = env_to_array(shell);
	code = execve(cmd, args, env);
	ms_arrfree(args);
	ms_arrfree(env);
	if (code != EXECVE_ERRN)
		ms_exit(code, NULL);
	if (errno == 2)
		err = "command not found";
	else
		err = strerror(errno);
	printf("minishell: %s: %s\n", cmd, err);
	exit(127);
}
