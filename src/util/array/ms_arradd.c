/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:27:32 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 22:37:39 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_utils.h"

char	**ms_arradd(char **arr, char *str)
{
	char	**new;
	t_ulong	size;
	t_ulong	i;

	if (arr == NULL)
	{
		new = ms_malloc(2 * sizeof(char **));
		new[0] = str;
		new[1] = NULL;
		return (new);
	}
	size = ms_arrlen((void **) arr);
	new = ms_malloc((size + 2) * sizeof(char **));
	i = 0;
	while (arr[i] != NULL)
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = str;
	new[i + 1] = NULL;
	return (new);
}
