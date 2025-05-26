/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:58:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/05/26 13:58:23 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ms_arrdup(const size_t from, const char **arr)
{
	size_t	i;
	size_t	len;
	char	**clone;

	len = 0;
	while (i < from)
	{
		if (arr[i] == NULL)
			return (NULL);
		len++;
	}
	clone = ms_malloc(len - from + 1 * sizeof(char *));
	i = 0;
	while (arr[from] != NULL)
	{
		clone[i] = ms_strdup(arr[from]);
		i++;
		from++;
	}
	clone[i] = NULL;
	return (clone);
}
