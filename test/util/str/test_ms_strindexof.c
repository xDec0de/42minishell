/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strindexof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:09:57 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:29:34 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "cde", 0), 2);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "z", 0), -1);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "abc", 1), -1);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "", 0), 0);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "", 6), 0);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "", 7), -1);
	ASSERT_INT_EQUALS(ms_strindexof("ababc", "abc", 0), 2);
	ASSERT_INT_EQUALS(ms_strindexof("abcabc", "abc", 3), 3);
	ASSERT_INT_EQUALS(ms_strindexof(NULL, "abc", 0), -1);
	ASSERT_INT_EQUALS(ms_strindexof("abc", NULL, 0), -1);
	ASSERT_INT_EQUALS(ms_strindexof("abc", "abc", 0), 0);
}
