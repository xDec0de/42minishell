/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:43:04 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/05 13:21:29 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_TYPES_H
# define MS_TYPES_H

/** bool type */
# include <stdbool.h>

/** NULL, STDERR_FILENO, STDIN_FILENO & STDOUT_FILENO */
# include <unistd.h>

/** Unsigned long long type. */
typedef unsigned long long	t_ulong;

# define FD_ERR STDERR_FILENO
# define FD_IN STDIN_FILENO
# define FD_OUT STDOUT_FILENO

#endif
