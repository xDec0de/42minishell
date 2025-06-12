/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:24:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/12 15:46:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test_minishell.h"

void test_ms_isdigit(void)
{
	TEST_ASSERT_FALSE_MESSAGE(ms_isdigit('0' - 1), "1");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('0'), "2");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('1'), "3");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('2'), "4");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('3'), "5");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('4'), "6");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('5'), "7");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('6'), "8");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('7'), "9");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('8'), "10");
	TEST_ASSERT_TRUE_MESSAGE(ms_isdigit('9'), "11");
	TEST_ASSERT_FALSE_MESSAGE(ms_isdigit('9' + 1), "12");
}
