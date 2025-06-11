/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:50:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/11 17:42:39 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*bltn_exit(t_shell *shell, char **args)
{
	unsigned char	code;
	int				atoi_res;

	code = EXEC_OK;
	if (args[0] != NULL)
	{
		atoi_res = ms_atoi(args[0], false, -1);
		if (atoi_res == -1)
		{
			code = EXIT_NOT_NUMERIC_ERRN;
			printf(EXIT_NOT_NUMERIC, args[0]);
		}
		else
			code = (unsigned char) atoi_res;
	}
	shell->running = false;
	return (build_cmd(code, NULL));
}
