/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strindexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:05:55 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:52:17 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_strindexof(const char *str, const char *substr, t_ulong start)
{
	t_ulong	i;
	t_ulong	j;

	if (str == NULL || substr == NULL || start >= ms_strlen(str))
		return (-1);
	if (substr[0] == '\0')
		return (0);
	i = start;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == substr[j] && substr[j] != '\0')
			j++;
		if (substr[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
