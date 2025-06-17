/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:35:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/17 17:36:41 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ms_calloc(size_t amount, size_t size)
{
	void	*str;
	size_t	final_size;

	final_size = amount * size;
	str = ms_malloc(final_size);
	ft_bzero(str, final_size);
	return (str);
}
