/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:00:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 01:08:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_shell	*init_shell(char **env)
{
	t_shell	*init;

	init = ms_malloc(sizeof(t_shell));
	init->last_input = NULL;
	init->last_tokens = NULL;
	init->last_exit_code = 0;
	init->env = NULL;
	env_init(init, env);
	return (store_shell(init));
}
