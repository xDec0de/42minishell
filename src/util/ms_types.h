/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:43:04 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 17:31:12 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_TYPES_H
# define MS_TYPES_H

/** bool type */
# include <stdbool.h>

/** NULL, STDERR_FILENO, STDIN_FILENO & STDOUT_FILENO */
# include <unistd.h>

/**
 * @brief Unsigned long long type used for sizes and indexes in minishell.
 */
typedef unsigned long long	t_ulong;


/**
 * @brief File descriptor for error output (stderr).
 */
# define FD_ERR STDERR_FILENO

/**
 * @brief File descriptor for standard input (stdin).
 */
# define FD_IN STDIN_FILENO

/**
 * @brief File descriptor for standard output (stdout).
 */
# define FD_OUT STDOUT_FILENO

#endif
