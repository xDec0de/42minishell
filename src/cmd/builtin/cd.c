/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:50:22 by rexposit          #+#    #+#             */
/*   Updated: 2025/06/29 17:50:16 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_home(t_shell *shell)
{
	t_env	*home;

	home = env_get(shell, "HOME");
	if (home == NULL)
		ms_exit(EXEC_FAIL, NULL);
	return (home->value);
}

void	bltn_cd(t_shell *shell, char **args)
{
	char	old_pwd[PATH_MAX];
	char	new_pwd[PATH_MAX];
	char	*path;

	if (getcwd(old_pwd, PATH_MAX) == NULL)
		ms_exit(EXEC_FAIL, NULL);
	if (args[0] == NULL)
		path = get_home(shell);
	else
		path = args[0];
	if (chdir(path) != 0)
	{
		perror("cd");
		ms_exit(EXEC_FAIL, NULL);
	}
	if (getcwd(new_pwd, PATH_MAX) == NULL)
		ms_exit(EXEC_FAIL, NULL);
	env_export(shell, ms_strjoin("OLDPWD", old_pwd, '='));
	env_export(shell, ms_strjoin("PWD", new_pwd, '='));
	ms_exit(EXEC_OK, NULL);
}
