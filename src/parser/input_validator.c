/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:23:00 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/15 20:46:02 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_special_char_count(const char *input)
{
	t_ulong	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '|' && ms_isspecial(input[i + 1]))
			return (ms_print(FD_ERR, SCC_ERR), false);
		if (input[i] == '>')
		{
			if (input[i + 1] == '>' && ms_isspecial(input[i + 2]))
				return (ms_print(FD_ERR, SCC_ERR), false);
			else if (input[i + 1] != '>' && ms_isspecial(input[i + 1]))
				return (ms_print(FD_ERR, SCC_ERR), false);
		}
		if (input[i] == '<')
		{
			if (input[i + 1] == '<' && ms_isspecial(input[i + 2]))
				return (ms_print(FD_ERR, SCC_ERR), false);
			else if (input[i + 1] != '<' && ms_isspecial(input[i + 1]))
				return (ms_print(FD_ERR, SCC_ERR), false);
		}
		i++;
	}
	return (true);
}

bool	check_quotes(const char *input)
{
	t_ulong	i;
	bool	in_single;
	bool	in_double;

	i = 0;
	in_single = false;
	in_double = false;
	while (input[i] != '\0')
	{
		if (!in_double && input[i] == '\'')
			in_single = !in_single;
		else if (!in_single && input[i] == '"')
			in_double = !in_double;
		i++;
	}
	return (!in_single && !in_double);
}

bool	check_first_special(const char *input)
{
	if (input[0] == '<')
		return (input[1] == '<');
	return (!ms_isspecial(input[0]));
}

bool	validate_input(const char *input)
{
	if (input == NULL || input[0] == '\0')
		return (false);
	if (!check_quotes(input))
	{
		ms_print(STDERR_FILENO, "minishell: Syntax error: Unclosed quotes.\n");
		return (false);
	}
	if (!check_first_special(input))
		return (ms_print(FD_ERR, SCC_ERR), false);
	if (!check_special_char_count(input))
		return (false);
	return (true);
}
