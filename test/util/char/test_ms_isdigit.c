/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:24:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/12 15:57:35 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test_minishell.h"

void	test_ms_isdigit(void)
{
	ASSERT_FALSE(ms_isdigit('0' - 1), 1);
	ASSERT_TRUE(ms_isdigit('0'), 2);
	ASSERT_TRUE(ms_isdigit('1'), 3);
	ASSERT_TRUE(ms_isdigit('2'), 4);
	ASSERT_TRUE(ms_isdigit('3'), 5);
	ASSERT_TRUE(ms_isdigit('4'), 6);
	ASSERT_TRUE(ms_isdigit('5'), 7);
	ASSERT_TRUE(ms_isdigit('6'), 8);
	ASSERT_TRUE(ms_isdigit('7'), 9);
	ASSERT_TRUE(ms_isdigit('8'), 10);
	ASSERT_TRUE(ms_isdigit('9'), 11);
	ASSERT_FALSE(ms_isdigit('9' + 1), 12);
}
