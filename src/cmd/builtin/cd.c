/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:50:22 by rexposit          #+#    #+#             */
/*   Updated: 2025/07/05 13:22:55 by daniema3         ###   ########.fr       */
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
	char	*path;
	int		chdir_res;

	if (args[0] == NULL)
		path = get_home(shell);
	else
		path = args[0];
	if (path == NULL)
		return (ms_print(FD_ERR, CD_NO_HOME), EXEC_FAIL);
	chdir_res = chdir(path);
	if (chdir_res != 0)
		return (perror(CD_CHDIR_ERR), chdir_res);
	path = getcwd(NULL, 0);
	if (path == NULL)
		return (ms_print(FD_ERR, CD_PWD_ERR), EXEC_FAIL);
	set_pwd(shell, path);
	free(path);
	return (EXEC_OK);
}
