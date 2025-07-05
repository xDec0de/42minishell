/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:17:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/05 11:24:05 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(t_shell *shell)
{
	char	pwd[PATH_MAX];
	t_env	*env_pwd;

	if (shell->pwd != NULL)
		return (shell->pwd);
	if (!getcwd(pwd, PATH_MAX))
	{
		env_pwd = env_get(shell, "PWD");
		if (env_pwd == NULL)
			return (NULL);
	}
	shell->pwd = ms_strdup(pwd);
	return (shell->pwd);
}

bool	set_pwd(t_shell *shell, char *pwd)
{
	char	*old_pwd;
	char	*new_pwd;

	if (pwd == NULL)
		return (false);
	old_pwd = ms_strjoin("OLDPWD", shell->pwd, '=');
	env_export(shell, old_pwd);
	free(old_pwd);
	free(shell->pwd);
	shell->pwd = ms_strdup(pwd);
	new_pwd = ms_strjoin("PWD", pwd, '=');
	env_export(shell, new_pwd);
	free(new_pwd);
	return (true);
}

void	bltn_pwd(t_shell *shell)
{
	if (shell->pwd == NULL)
		ms_exit(EXEC_FAIL, NULL);
	printf("%s\n", shell->pwd);
	ms_exit(EXEC_OK, NULL);
}
