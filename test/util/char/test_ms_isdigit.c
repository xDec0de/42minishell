/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:24:13 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:27:50 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "char_utils.h"

int	main(void)
{
	ASSERT_FALSE(ms_isdigit('0' - 1));
	ASSERT_TRUE(ms_isdigit('0'));
	ASSERT_TRUE(ms_isdigit('1'));
	ASSERT_TRUE(ms_isdigit('2'));
	ASSERT_TRUE(ms_isdigit('3'));
	ASSERT_TRUE(ms_isdigit('4'));
	ASSERT_TRUE(ms_isdigit('5'));
	ASSERT_TRUE(ms_isdigit('6'));
	ASSERT_TRUE(ms_isdigit('7'));
	ASSERT_TRUE(ms_isdigit('8'));
	ASSERT_TRUE(ms_isdigit('9'));
	ASSERT_FALSE(ms_isdigit('9' + 1));
}
