/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:50:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 18:26:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bltn_exit(char **args)
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
	ms_arrfree(args);
	ms_exit(code, NULL);
}
