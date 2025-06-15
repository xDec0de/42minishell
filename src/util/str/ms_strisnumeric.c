/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strisnumeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:37:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/15 19:45:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_strisnumeric(const char *str, bool allow_spaces)
{
	int		i;
	bool	found_digit;

	i = 0;
	found_digit = false;
	if (str == NULL)
		return (false);
	while (allow_spaces && str[i] != '\0' && ms_isspace(str[i]))
		i++;
	while (str[i] != '\0' && ms_isdigit(str[i]))
	{
		found_digit = true;
		i++;
	}
	if (!found_digit)
		return (false);
	while (str[i] != '\0')
	{
		if (!allow_spaces || !ms_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}
