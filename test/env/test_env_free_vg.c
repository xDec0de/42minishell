/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_free_vg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:50:37 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:11:16 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_assertions.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void) argc;
	(void) argv;
	shell = ms_malloc(sizeof(t_shell));
	shell->env = NULL;
	env_init(shell, env);
	ASSERT_NOT_NULL(shell->env, 1);
	env_free(shell);
	ASSERT_NULL(shell->env, 2);
	free(shell);
	return (0);
}
