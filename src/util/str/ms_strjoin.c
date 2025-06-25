/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:49:09 by rexposit          #+#    #+#             */
/*   Updated: 2025/06/25 15:48:17 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_strjoin(char const *s1, char const *s2)
{
	size_t	s1_s2_len;
	size_t	i;
	size_t	j;
	char	*ptr;

	s1_s2_len = ms_strlen(s1) + ms_strlen(s2);
	ptr = ms_malloc(s1_s2_len + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
