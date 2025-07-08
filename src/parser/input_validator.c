/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:23:00 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:14:23 by daniema3         ###   ########.fr       */
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

bool	check_quotes(const char *line)
{
	t_ulong	i;
	bool	in_single;
	bool	in_double;

	i = 0;
	in_single = false;
	in_double = false;
	while (line[i] != '\0')
	{
		if (!in_double && line[i] == '\'')
			in_single = !in_single;
		else if (!in_single && line[i] == '"')
			in_double = !in_double;
		i++;
	}
	return (!in_single && !in_double);
}

bool	validate_input(const char *line)
{
	return (check_quotes(line) && check_special_char_count(line));
}
