/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:00:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/05 10:51:57 by daniema3         ###   ########.fr       */
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
	init->pwd = NULL;
	env_init(init, env);
	return (store_shell(init));
}
