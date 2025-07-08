/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_arr_dup_free_vg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:52:31 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:27:17 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "array_utils.h"

int	main(void)
{
	ASSERT_NULL(ms_arrdup(0L, NULL));
	char* arr[3] = {"Hello", "42", NULL};

	char** dup = ms_arrdup(0, arr);
	ASSERT_NOT_NULL(dup);
	ASSERT_STR_EQUALS(dup[0], "Hello");
	ASSERT_STR_EQUALS(dup[1], "42");
	ASSERT_NULL(dup[2]);
	ms_arrfree(dup);

	dup = ms_arrdup(1, arr);
	ASSERT_STR_EQUALS(dup[0], "42");
	ASSERT_NULL(dup[1]);
	ms_arrfree(dup);

	dup = ms_arrdup(2, arr);
	ASSERT_NULL(dup[0]);
	ms_arrfree(dup);

	dup = ms_arrdup(3, arr);
	ASSERT_NULL(dup);
}
