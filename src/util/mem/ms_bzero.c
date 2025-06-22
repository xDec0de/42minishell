/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:35:16 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:09:10 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_types.h"

void	ms_bzero(void	*str, t_ulong n)
{
	t_ulong			i;
	unsigned char	*casted_str;

	i = 0;
	casted_str = str;
	while (i < n)
	{
		casted_str[i] = '\0';
		i++;
	}
}
