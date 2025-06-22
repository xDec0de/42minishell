/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strindexof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:09:57 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 13:19:59 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int	main(void)
{
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "cde", 0), 2, 1);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "z", 0), -1, 2);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "abc", 1), -1, 3);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "", 0), 0, 4);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "", 6), 0, 5);
	ASSERT_INT_EQUALS(ms_strindexof("abcdefg", "", 7), -1, 6);
	ASSERT_INT_EQUALS(ms_strindexof("ababc", "abc", 0), 2, 7);
	ASSERT_INT_EQUALS(ms_strindexof("abcabc", "abc", 3), 3, 8);
	ASSERT_INT_EQUALS(ms_strindexof(NULL, "abc", 0), -1, 9);
	ASSERT_INT_EQUALS(ms_strindexof("abc", NULL, 0), -1, 10);
	ASSERT_INT_EQUALS(ms_strindexof("abc", "abc", 0), 0, 11);
}
