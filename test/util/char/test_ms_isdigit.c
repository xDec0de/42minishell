/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:24:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/12 13:56:11 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test_minishell.h"

void test_ms_isdigit(void)
{
	TEST_ASSERT_FALSE(ms_isdigit('0' - 1));
	TEST_ASSERT_TRUE(ms_isdigit('0'));
	TEST_ASSERT_TRUE(ms_isdigit('1'));
	TEST_ASSERT_TRUE(ms_isdigit('2'));
	TEST_ASSERT_TRUE(ms_isdigit('3'));
	TEST_ASSERT_TRUE(ms_isdigit('4'));
	TEST_ASSERT_TRUE(ms_isdigit('5'));
	TEST_ASSERT_TRUE(ms_isdigit('6'));
	TEST_ASSERT_TRUE(ms_isdigit('7'));
	TEST_ASSERT_TRUE(ms_isdigit('8'));
	TEST_ASSERT_TRUE(ms_isdigit('9'));
	TEST_ASSERT_FALSE(ms_isdigit('9' + 1));
}
