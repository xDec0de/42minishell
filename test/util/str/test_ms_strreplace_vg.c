/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strreplace_vg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 21:29:19 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:30:21 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	FREE_ASSERT_STR_EQUALS(ms_strreplace("Hi, world!", 0, 2, "Hello"), "Hello, world!");
	FREE_ASSERT_STR_EQUALS(ms_strreplace("Hi, world!", 2, 7, " everyone"), "Hi everyone!");
	FREE_ASSERT_STR_EQUALS(ms_strreplace("Hi", 0, 2, "Hello"), "Hello");
	ASSERT_NULL(ms_strreplace("Hi", 0, 3, "Hello"));
	ASSERT_NULL(ms_strreplace("Hi", 0, 0, NULL));
	ASSERT_NULL(ms_strreplace(NULL, 0, 0, NULL));
}
