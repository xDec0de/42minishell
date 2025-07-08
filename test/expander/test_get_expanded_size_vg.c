/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_expanded_size_vg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:36:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:24:54 by daniema3         ###   ########.fr       */
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
	ASSERT_ULONG_EQUALS(get_expanded_size(shell, "echo hello"), 10L);
	ASSERT_ULONG_EQUALS(get_expanded_size(shell, "echo $?"), 6L);
	env_export(shell, "TEST_VAR=42");
	ASSERT_ULONG_EQUALS(get_expanded_size(shell, "echo $TEST_VAR"), 7L);
	ASSERT_ULONG_EQUALS(get_expanded_size(shell, "echo '$TEST_VAR'"), 14L);
	ASSERT_ULONG_EQUALS(get_expanded_size(shell, "echo $"), 6L);
	ms_exit(EXEC_OK, NULL);
}
