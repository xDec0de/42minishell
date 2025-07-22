/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:11:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/22 18:54:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_n_flag(char *str)
{
	t_ulong	i;

	i = 0;
	if (str == NULL)
		return (false);
	if (str[i] != '-')
		return (false);
	i++;
	if (str[i] != 'n')
		return (false);
	while (str[i] == 'n')
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

void	bltn_echo(char **args)
{
	t_ulong	i;
	bool	nl;
	bool	first_written;

	i = 0;
	nl = true;
	first_written = false;
	while (args[i] != NULL && is_n_flag(args[i]))
	{
		nl = false;
		i++;
	}
	while (args[i] != NULL)
	{
		if (!first_written)
			first_written = printf("%s", args[i]);
		else
			printf(" %s", args[i]);
		i++;
	}
	if (nl)
		printf("\n");
	ms_exit(EXEC_OK, NULL);
}
