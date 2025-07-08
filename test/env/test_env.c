/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:00:21 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:24:20 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_assertions.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void) argc;
	(void) argv;
	shell = init_shell(env);
	ASSERT_NOT_NULL(shell->env);
	// Export and get
	env_export(shell, "TEST_VAR=12345");
	ASSERT_STR_EQUALS(env_get(shell, "TEST_VAR")->key, "TEST_VAR");
	ASSERT_STR_EQUALS(env_get(shell, "TEST_VAR")->value, "12345");
	// Redefinie and get
	env_export(shell, "TEST_VAR=123");
	ASSERT_STR_EQUALS(env_get(shell, "TEST_VAR")->key, "TEST_VAR");
	ASSERT_STR_EQUALS(env_get(shell, "TEST_VAR")->value, "123");
	// Unset
	env_unset(shell, "TEST_VAR");
	ASSERT_NULL(env_get(shell, "TEST_VAR"));
	// Free
	env_free(shell);
	ASSERT_NULL(shell->env);
	ms_exit(0, NULL);
}
