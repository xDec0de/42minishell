/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:30:47 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/27 21:42:06 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	catch_sigint(int signum)
{
	t_shell	*shell;

	shell = get_shell();
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	if (shell->heredoc_pid != 0)
	{
		kill(shell->heredoc_pid, SIGINT);
		shell->heredoc_pid = 0;
	}
	else if (shell->cmd_pid != 0)
	{
		kill(shell->cmd_pid, SIGINT);
		shell->cmd_pid = 0;
	}
	else
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	catch_sigquit(int signum)
{
	if (signum != SIGQUIT)
		return ;
	rl_on_new_line();
	rl_replace_line("  ", 0);
	rl_redisplay();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	init_handler(int signum, __sighandler_t handler)
{
	struct sigaction	new_action;

	new_action.sa_handler = handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(signum, &new_action, NULL);
}

void	init_sighandler(void)
{
	init_handler(SIGINT, catch_sigint);
	init_handler(SIGQUIT, catch_sigquit);
}
