/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:35:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:09:37 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_utils.h"

void	*ms_calloc(t_ulong amount, t_ulong size)
{
	void	*str;
	t_ulong	final_size;

	final_size = amount * size;
	str = ms_malloc(final_size);
	ms_bzero(str, final_size);
	return (str);
}
