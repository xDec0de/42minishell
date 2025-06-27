/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:50:22 by rexposit          #+#    #+#             */
/*   Updated: 2025/06/27 21:21:23 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*bltn_cd(t_shell *shell, char **args)
{
	char	old_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];
	char	*path;
	t_env	*home;

	if (getcwd(old_pwd, PATH_MAX) == NULL)
		return (build_cmd(EXEC_FAIL, NULL, true));
	if (args[0] == NULL)
	{
		home = env_get(shell, "HOME");
		if (!home)
			return (build_cmd(EXEC_FAIL, NULL, true));
		path = home->value;
	}
	else
		path = args[0];
	if (chdir(path) != 0)
		return (perror("cd"), build_cmd(EXEC_FAIL, NULL, true));
	if (getcwd(new_pwd, PATH_MAX) == NULL)
		return (build_cmd(EXEC_FAIL, NULL, true));
	env_export(shell, ms_strjoin("OLDPWD", old_pwd, '='));
	env_export(shell, ms_strjoin("PWD", new_pwd, '='));
	return (build_cmd(EXEC_OK, NULL, true));
}
