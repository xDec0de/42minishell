/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:46:58 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/14 17:58:35 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ms_strequals(char *str, char *other)
{
	size_t	len;
	size_t	i;

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
