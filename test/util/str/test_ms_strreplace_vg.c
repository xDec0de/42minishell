/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strreplace_vg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:29:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:15:17 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	FREE_ASSERT_STR_EQUALS(ms_strreplace("Hi, world!", 0, 2, "Hello"), "Hello, world!", 1);
	FREE_ASSERT_STR_EQUALS(ms_strreplace("Hi, world!", 2, 7, " everyone"), "Hi everyone!", 1);
	FREE_ASSERT_STR_EQUALS(ms_strreplace("Hi", 0, 2, "Hello"), "Hello", 2);
	ASSERT_NULL(ms_strreplace("Hi", 0, 3, "Hello"), 3);
	ASSERT_NULL(ms_strreplace("Hi", 0, 0, NULL), 4);
	ASSERT_NULL(ms_strreplace(NULL, 0, 0, NULL), 5);
}
