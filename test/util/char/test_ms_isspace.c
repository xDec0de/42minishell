/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:03:12 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:14:19 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "char_utils.h"

int	main(void)
{
	ASSERT_TRUE(ms_isspace(' '), 1);
	ASSERT_TRUE(ms_isspace('\t'), 2);
	ASSERT_TRUE(ms_isspace('\n'), 3);
	ASSERT_TRUE(ms_isspace('\r'), 4);
	ASSERT_TRUE(ms_isspace('\f'), 5);
	ASSERT_TRUE(ms_isspace('\v'), 6);
	ASSERT_FALSE(ms_isspace('\0'), 7);
}
