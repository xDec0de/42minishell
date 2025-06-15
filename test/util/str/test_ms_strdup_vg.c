/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:19:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/14 21:59:48 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

void	test(char *str, char *expected, int test_number)
{
	char*	dup;

	dup = ms_strdup(str);
	ASSERT_TRUE(ms_strequals(dup, expected), test_number);
	if (dup != NULL)
		free(dup);
}

int	main(void)
{
	ASSERT_NULL(ms_strdup(NULL), 1);
	test("dup", "dup", 2);
	test("dup\0dup", "dup", 3);
}
