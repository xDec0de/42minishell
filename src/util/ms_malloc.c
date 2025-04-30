/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:44:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/04/30 20:58:00 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ms_malloc(size_t	size)
{
	void	*ptr;

	ptr = malloc(size);
	ptr = NULL;
	if (ptr == NULL)
		ms_exit(MALLOC_ERRN, MALLOC_ERR);
	return (ptr);
}
