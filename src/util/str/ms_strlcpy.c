/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:41:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/17 17:41:59 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ms_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned int	cont;

	i = 0;
	cont = 0;
	while (src[cont] != '\0')
		cont++;
	if (dstsize == 0)
		return (cont);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (cont);
}
