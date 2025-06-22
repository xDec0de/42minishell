/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:00:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 18:04:51 by daniema3         ###   ########.fr       */
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
	// Init
	env_init(shell, env);
	ASSERT_NOT_NULL(shell->env, 1);
	// Export and get
	env_export(shell, "TEST_VAR=12345");
	ASSERT_STR_EQUALS(env_get(shell, "TEST_VAR")->value, "12345", 2);
	// Redefinie and get
	env_export(shell, "TEST_VAR=123");
	ASSERT_STR_EQUALS(env_get(shell, "TEST_VAR")->value, "123", 3);
	// Unset
	env_unset(shell, "TEST_VAR");
	ASSERT_NULL(env_get(shell, "TEST_VAR"), 4);
	// Free
	env_free(shell);
	ASSERT_NULL(shell->env, 5);
	free(shell);
	return (0);
}
