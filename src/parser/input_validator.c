/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:23:00 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:19:05 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"

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
