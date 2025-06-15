/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_arr_dup_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:52:31 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/15 17:09:33 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int	main(void)
{
	ASSERT_NULL(ms_arrdup(0L, NULL), 1);
	char* arr[3] = {"Hello", "42", NULL};

	char** dup = ms_arrdup(0, arr);
	ASSERT_NOT_NULL(dup, 2);
	ASSERT_STR_EQUALS(dup[0], "Hello", 3);
	ASSERT_STR_EQUALS(dup[1], "42", 4);
	ASSERT_NULL(dup[2], 5);
	ms_arrfree(dup);

	dup = ms_arrdup(1, arr);
	ASSERT_STR_EQUALS(dup[0], "42", 5);
	ASSERT_NULL(dup[1], 6);
	ms_arrfree(dup);

	dup = ms_arrdup(2, arr);
	ASSERT_NULL(dup[0], 7);
	ms_arrfree(dup);

	dup = ms_arrdup(3, arr);
	ASSERT_NULL(dup, 8);
}
