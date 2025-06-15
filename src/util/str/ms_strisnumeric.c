/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strisnumeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:37:09 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/15 20:08:47 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_leading_spaces(const char *str, int i)
{
	while (str[i] != '\0' && ms_isspace(str[i]) == true)
		i++;
	return (i);
}

static int	skip_digits(const char *str, int i, bool *found_digit)
{
	while (str[i] != '\0' && ms_isdigit(str[i]) == true)
	{
		*found_digit = true;
		i++;
	}
	return (i);
}

static bool	validate_trailing(const char *str, int i, bool allow_spaces)
{
	if (allow_spaces == true)
	{
		while (str[i] != '\0')
		{
			if (ms_isspace(str[i]) == false)
				return (false);
			i++;
		}
	}
	else if (str[i] != '\0')
		return (false);
	return (true);
}

bool	ms_strisnumeric(const char *str, bool allow_spaces)
{
	int		i;
	bool	found_digit;

	i = 0;
	found_digit = false;
	if (str == NULL)
		return (false);
	if (allow_spaces == true)
		i = skip_leading_spaces(str, i);
	i = skip_digits(str, i, &found_digit);
	if (found_digit == false)
		return (false);
	return (validate_trailing(str, i, allow_spaces));
}
