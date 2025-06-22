/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:46:58 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:52:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_strequals(char *str, char *other)
{
	t_ulong	len;
	t_ulong	i;

	if (str == NULL || other == NULL)
		return (str == other);
	i = 0;
	len = ms_strlen(str);
	if (len != ms_strlen(other))
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] != other[i])
			return (false);
		i++;
	}
	return (true);
}
