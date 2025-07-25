/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:27:10 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 12:27:16 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"

int	ms_strncmp(const char *s1, const char *s2, t_ulong n)
{
	t_ulong	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
