/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:23:59 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 17:30:16 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_UTILS_H
# define MS_UTILS_H

# include "ms_types.h"
# include "array_utils.h"
# include "char_utils.h"
# include "mem_utils.h"
# include "str_utils.h"

/**
 * @brief Prints a message to the specified file descriptor.
 *
 * Works similarly to dprintf but simplified for minishell needs.
 *
 * @param fd The file descriptor to print to (1 for stdout, 2 for stderr).
 * @param msg The message to print (NULL-terminated string).
 */
void	ms_print(int fd, char *msg);

#endif
