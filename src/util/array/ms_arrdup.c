/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:58:48 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/12 14:11:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ms_arrdup(size_t from, char **arr)
{
	size_t	i;
	size_t	arrlen;
	char	**clone;

	if (arr == NULL)
		return (NULL);
	i = 0;
	arrlen = ms_arrlen((void **) arr);
	if (arrlen < from)
		return (NULL);
	clone = ms_malloc((arrlen - from + 2) * sizeof(char *));
	while (arr[from] != NULL)
	{
		clone[i] = ms_strdup(arr[from]);
		i++;
		from++;
	}
	clone[i] = NULL;
	return (clone);
}
