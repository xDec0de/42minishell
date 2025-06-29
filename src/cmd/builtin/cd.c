/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:50:22 by rexposit          #+#    #+#             */
/*   Updated: 2025/06/29 18:48:49 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_home(t_shell *shell)
{
	t_env	*home;

	home = env_get(shell, "HOME");
	if (home == NULL)
		return (NULL);
	return (home->value);
}

int	bltn_cd(t_shell *shell, char **args)
{
	char	old_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];
	char	*path;

	if (getcwd(old_pwd, PATH_MAX) == NULL)
		return (EXEC_FAIL);
	if (args[0] == NULL)
		path = get_home(shell);
	else
		path = args[0];
	if (path == NULL)
		return (EXEC_FAIL);
	if (chdir(path) != 0)
		return (perror("cd"), EXEC_FAIL);
	if (getcwd(new_pwd, PATH_MAX) == NULL)
		return (EXEC_FAIL);
	env_export(shell, ms_strjoin("OLDPWD", old_pwd, '='));
	env_export(shell, ms_strjoin("PWD", new_pwd, '='));
	return (EXEC_FAIL);
}
