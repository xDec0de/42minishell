/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:58:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/05/26 18:10:31 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ms_arrdup(size_t from, char **arr)
{
	size_t	i;
	size_t	len;
	char	**clone;

	len = 0;
	i = 0;
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
