/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:30:40 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 17:24:37 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_UTILS_H
# define MEM_UTILS_H

# include "ms_types.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * @param str Pointer to the memory block to clear.
 * @param n Number of bytes to set to zero.
 */
void	ms_bzero(void	*str, t_ulong n);

/**
 * @brief Allocates memory for an array and initializes it to zero.
 *
 * Works similarly to the standard calloc.
 *
 * @param amount Number of elements to allocate.
 * @param size Size (in bytes) of each element.
 *
 * @return A pointer to the allocated and zero-initialized memory,
 *         or NULL on allocation failure.
 */
void	*ms_calloc(t_ulong amount, t_ulong size);

/**
 * @brief Allocates memory for a single block (uninitialized).
 *
 * Works similarly to the standard malloc, but include custom
 * error handling in minishell.
 *
 * @param size Size (in bytes) to allocate.
 *
 * @return A pointer to the allocated memory, or NULL on failure.
 */
void	*ms_malloc(t_ulong	size);

#endif