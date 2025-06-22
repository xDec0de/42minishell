/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:30:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:32:30 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_UTILS_H
# define MEM_UTILS_H

/* bool type */
# include <stdbool.h>

/* malloc & size_t */
# include <unistd.h>

void	ms_bzero(void	*str, size_t n);

void	*ms_calloc(size_t amount, size_t size);

void	*ms_malloc(size_t	size);

#endif