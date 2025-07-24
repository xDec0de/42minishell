/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_vg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:30:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/24 21:04:30 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void) argc;
	(void) argv;
	shell = init_shell(env);
	env_export(shell, "TEST_VAR=42");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $TEST_VAR"), "echo 42");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $TEST_VAR/a"), "echo 42/a");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $TEST_VAR school"), "echo 42 school");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $TEST_VAR | cat -e"), "echo 42 | cat -e");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $TEST_VARR"), "echo ");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo \'$TEST_VAR\'"), "echo $TEST_VAR");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $?"), "echo 0");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $?a"), "echo 0a");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo \'$?\'"), "echo $?");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo \'\'$?\'\'"), "echo 0");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo \'\'\'$?\'\'\'"), "echo $?");
	FREE_ASSERT_STR_EQUALS(expand(shell, "echo $ | cat -e"), "echo $ | cat -e");
	ms_exit(EXEC_OK, NULL);
}
