/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:03:12 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:28:04 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "char_utils.h"

int	main(void)
{
	ASSERT_TRUE(ms_isspace(' '));
	ASSERT_TRUE(ms_isspace('\t'));
	ASSERT_TRUE(ms_isspace('\n'));
	ASSERT_TRUE(ms_isspace('\r'));
	ASSERT_TRUE(ms_isspace('\f'));
	ASSERT_TRUE(ms_isspace('\v'));
	ASSERT_FALSE(ms_isspace('\0'));
}
