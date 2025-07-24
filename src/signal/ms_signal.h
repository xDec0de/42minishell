/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:20:16 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 17:22:04 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_SIGNAL_H
# define MS_SIGNAL_H

/* printf */
# include <stdio.h>

/* signal functions & signal numbers */
# include <signal.h>

/* readline */
# include <readline/readline.h>

/**
 * @brief Initializes custom signal handling for the minishell.
 *
 * This sets up handlers to properly manage:
 * - SIGINT (Ctrl + C): Clears the current input line and shows a new prompt.
 * - SIGQUIT (Ctrl + \): Ignored in interactive mode.
 */
void	init_sighandler(void);

#endif
