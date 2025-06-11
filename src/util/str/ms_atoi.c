/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:53:01 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/11 17:21:39 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_atoi_space(char ch)
{
	return (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == ' ');
}

int	ms_atoi(const char *str, bool allow_spaces, int def)
{
	unsigned long		i;
	unsigned long long	res;
	bool				negative;

	i = 0;
	res = 0;
	negative = false;
	while (is_atoi_space(str[i]))
	{
		if (!allow_spaces)
			return (def);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative = true;
	while (ms_isdigit(str[i]))
		res = (res * 10) + (str[i++] - '0');
	if (res > __LONG_MAX__)
		return (def);
	if (negative)
		return (-res);
	return (res);
}
