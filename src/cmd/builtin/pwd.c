/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:17:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 18:38:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bltn_pwd(char *cmd, char **args)
{
	char	pwd[PATH_MAX];

	if (!getcwd(pwd, PATH_MAX))
		ms_exit(EXEC_FAIL, NULL);
	printf("%s\n", pwd);
	free(cmd);
	ms_arrfree(args);
	ms_exit(EXEC_OK, NULL);
}
