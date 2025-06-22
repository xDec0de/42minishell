/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:30:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:47:36 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_UTILS_H
# define MEM_UTILS_H

# include "ms_types.h"

void	ms_bzero(void	*str, t_ulong n);

void	*ms_calloc(t_ulong amount, t_ulong size);

void	*ms_malloc(t_ulong	size);

#endif