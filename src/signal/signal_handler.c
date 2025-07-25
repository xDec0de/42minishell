/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:30:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/25 18:25:21 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sig_handler(int signum)
{
	t_shell	*shell;

	shell = get_shell();
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		if (shell->heredoc_pid != 0)
			kill(shell->heredoc_pid, SIGINT);
		else if (shell->cmd_pid != 0)
			kill(shell->cmd_pid, SIGINT);
		else
		{
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("  ", 0);
		rl_redisplay();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	init_sighandler(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
