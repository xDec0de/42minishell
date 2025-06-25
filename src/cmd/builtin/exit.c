/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:50:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 19:53:57 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*bltn_exit(t_shell *shell, char **args)
{
	unsigned char	code;
	char			*code_str;

	code = EXEC_OK;
	code_str = args[0];
	if (code_str != NULL)
	{
		if (!ms_strisnumeric(code_str, true))
		{
			code = EXIT_NOT_NUMERIC_ERRN;
			printf(EXIT_NOT_NUMERIC, code_str);
		}
		else
			code = (unsigned char) ms_atoi(code_str);
	}
	shell->running = false;
	return (build_cmd(code, NULL));
}
