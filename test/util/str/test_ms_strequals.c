/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strequals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:43:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:29:16 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_TRUE(ms_strequals(NULL, NULL));
	ASSERT_TRUE(ms_strequals("", ""));
	ASSERT_TRUE(ms_strequals("Hello", "Hello"));
	ASSERT_FALSE(ms_strequals("Helloo", "Hello"));
	ASSERT_FALSE(ms_strequals(NULL, ""));
	ASSERT_FALSE(ms_strequals("", NULL));
	ASSERT_FALSE(ms_strequals("HI", "Hi"));
}
