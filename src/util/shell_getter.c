/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:00:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/04/30 22:28:31 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_shell	*store_shell(t_shell *init)
{
	static t_shell	*shell;

	if (init != NULL)
		shell = init;
	return (shell);
}

t_shell	*get_shell(void)
{
	return (store_shell(NULL));
}

t_shell	*init_shell(void)
{
	t_shell	*init;

	init = ms_malloc(sizeof(t_shell));
	init->running = true;
	init->last_input = NULL;
	return (store_shell(init));
}
