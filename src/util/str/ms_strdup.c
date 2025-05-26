/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:32:32 by daniema3          #+#    #+#             */
/*   Updated: 2025/05/26 13:42:24 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ms_strdup(const char *str)
{
	char	*dup;
	size_t	len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
		len++;
	dup = ms_malloc(len + 1);
	len = 0;
	while (str[len] != '\0')
	{
		dup[len] = str[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
