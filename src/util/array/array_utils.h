/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:35:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/29 22:32:59 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

# include "mem_utils.h"

char	**ms_arradd(char **arr, char *str);

/**
 * @brief Returns a `NULL` terminated array duplicate
 * of the provided `arr`, starting at the `from` index.
 * Strings inside the array are also duplicated with
 * `ms_strdup`
 * 
 * @param from The index at which the duplication will start.
 * @param arr The array to duplicated. It is expected
 * that this array is `NULL` terminated, the behaviour
 * is undefined otherwise.
 * 
 * @return A duplicate of `arr`, from `from` to its end.
 * `NULL` if `from` is bigger than the length of `arr`, or
 * if `arr` itself is `NULL`.
 */
char	**ms_arrdup(t_ulong from, char **arr);

/**
 * @brief Frees the provided `arr` and all of its contents.
 * 
 * @param arr The array to free. It is expected
 * that this array is `NULL` terminated, the behaviour
 * is undefined otherwise.
 */
void	ms_arrfree(char **arr);

t_ulong	ms_arrlen(void **arr);

#endif
