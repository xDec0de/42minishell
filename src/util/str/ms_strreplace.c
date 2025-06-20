/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:19:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/20 23:05:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_strreplace(char *str, size_t from, size_t size, char *replacement)
{
	char	*replaced;
	size_t	i;
	size_t	rep_i;

	i = 0;
	rep_i = 0;
	if (str == NULL || replacement == NULL || ms_strlen(str) < (from + size))
		return (NULL);
	replaced = ms_calloc(ms_strlen(str) - size
			+ ms_strlen(replacement) + 1, sizeof(char));
	while (i < from)
		replaced[rep_i++] = str[i++];
	i = 0;
	while (i < ms_strlen(replacement))
		replaced[rep_i++] = replacement[i++];
	i = from + size;
	while (i < ms_strlen(str))
		replaced[rep_i++] = str[i++];
	replaced[rep_i] = '\0';
	return (replaced);
}
