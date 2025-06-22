/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 14:20:16 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:24:33 by daniema3         ###   ########.fr       */
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

void	init_sighandler(void);

#endif
