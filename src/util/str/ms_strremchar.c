/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strremchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:08:04 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/26 19:20:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_utils.h"
#include "ms_types.h"

char	*ms_strremchar(const char *str, const char ch)
{
	char	*new;
	t_ulong	size;
	t_ulong	str_i;
	t_ulong	new_i;

	size = 1;
	str_i = 0;
	while (str[str_i] != '\0')
		if (str[str_i++] != ch)
			size++;
	new = ms_calloc(size, sizeof(char));
	str_i = 0;
	new_i = 0;
	while (str[str_i] != '\0')
	{
		if (str[str_i] != ch)
		{
			new[new_i] = str[str_i];
			new_i++;
		}
		str_i++;
	}
	new[new_i] = '\0';
	return (new);
}
