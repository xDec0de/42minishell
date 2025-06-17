/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:18:10 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/17 17:51:14 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (str == NULL)
		return (NULL);
	if (ms_strlen(str) < start)
		return (ms_strdup(""));
	size = ms_strlen(&str[start]);
	if (size < len)
		len = size;
	if (len + 1 > len)
		substr = ms_calloc(len + 1, sizeof(char));
	else
		substr = ms_calloc(len, sizeof(char));
	if (substr == NULL)
		return (NULL);
	ms_strlcpy(substr, &str[start], len + 1);
	return (substr);
}
