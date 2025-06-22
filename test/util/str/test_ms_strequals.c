/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strequals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:43:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:14:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_TRUE(ms_strequals(NULL, NULL), 1);
	ASSERT_TRUE(ms_strequals("", ""), 2);
	ASSERT_TRUE(ms_strequals("Hello", "Hello"), 3);
	ASSERT_FALSE(ms_strequals("Helloo", "Hello"), 4);
	ASSERT_FALSE(ms_strequals(NULL, ""), 5);
	ASSERT_FALSE(ms_strequals("", NULL), 6);
	ASSERT_FALSE(ms_strequals("HI", "Hi"), 7);
}
