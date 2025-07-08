/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:00:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:22:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_assertions.h"

int	main(void)
{
	t_shell	*shell;
	char	**arr;

	shell = init_shell(NULL);
	arr = env_to_array(shell);
	ASSERT_NOT_NULL(arr);
	ASSERT_NULL(arr[0]);
	env_export(shell, "CODE=42");
	env_export(shell, "TEST=a");
	arr = env_to_array(shell);
	ASSERT_NOT_NULL(arr);
	ASSERT_STR_EQUALS(arr[0], "CODE=42");
	ASSERT_STR_EQUALS(arr[1], "TEST=a");
	ASSERT_NULL(arr[2]);
	ms_arrfree(arr);
	ms_exit(EXEC_OK, NULL);
}