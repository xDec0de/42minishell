/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:11:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 19:53:52 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*bltn_echo(char **args)
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
	return (build_cmd(EXEC_OK, NULL));
}
