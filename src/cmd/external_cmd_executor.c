/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:48:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 21:22:08 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*execute_external(t_shell *shell, char *cmd, char **args)
{
	int		code;
	char	**env;

	env = env_to_array(shell);
	code = execve(cmd, args, env);
	ms_arrfree(env);
	return (build_cmd(code, NULL, false));
}
