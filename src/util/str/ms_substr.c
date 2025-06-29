/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:18:10 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 18:38:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_substr(const char *str, unsigned int start, t_ulong len)
{
	char	*substr;
	t_ulong	size;

	if (str == NULL)
		return (NULL);
	if (ms_strlen(str) < start)
		return (ms_strdup(""));
	size = ms_strlen(&str[start]);
	if (size < len)
		len = size;
	substr = ms_calloc(len + 1, sizeof(char));
	ms_strlcpy(substr, &str[start], len + 1);
	return (substr);
}
