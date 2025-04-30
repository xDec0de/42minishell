/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:30:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/04/30 22:41:05 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_handler(int signum)
{
	if (signum == SIGINT)
		printf("\n");
	rl_on_new_line();
	if (signum == SIGQUIT)
	{
		rl_replace_line("  ", 0);
		rl_redisplay();
	}
	rl_replace_line("", 0);
	rl_redisplay();
}

void	init_sighandler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
