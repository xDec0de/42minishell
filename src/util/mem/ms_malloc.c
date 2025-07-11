/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:44:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:48:20 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ms_malloc(t_ulong	size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ms_exit(MALLOC_ERRN, MALLOC_ERR);
	return (ptr);
}
