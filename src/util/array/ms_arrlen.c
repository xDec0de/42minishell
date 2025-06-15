/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:19:03 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/15 16:50:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ms_arrlen(void **arr)
{
	size_t	len;

	if (arr == NULL)
		return (0);
	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
