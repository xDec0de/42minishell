/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:11:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 18:37:36 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bltn_echo(char *cmd, char **args)
{
	int		i;
	bool	nl;
	bool	first_written;

	i = 0;
	nl = true;
	first_written = false;
	while (args[i] != NULL)
	{
		if (ms_strequals("-n", args[i]))
			nl = false;
		else if (!first_written)
		{
			printf("%s", args[i]);
			first_written = true;
		}
		else
			printf(" %s", args[i]);
		i++;
	}
	if (nl)
		printf("\n");
	free(cmd);
	ms_arrfree(args);
	ms_exit(EXEC_OK, NULL);
}
