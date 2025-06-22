/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strisnumeric.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:47:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:15:06 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_TRUE(ms_strisnumeric("42", true), 1);
	ASSERT_TRUE(ms_strisnumeric("42", false), 2);
	ASSERT_TRUE(ms_strisnumeric(" 42", true), 3);
	ASSERT_TRUE(ms_strisnumeric("42 ", true), 4);
	ASSERT_TRUE(ms_strisnumeric("\t 42 \t", true), 5);
	ASSERT_FALSE(ms_strisnumeric(" 42", false), 6);
	ASSERT_FALSE(ms_strisnumeric("42 ", false), 7);
	ASSERT_FALSE(ms_strisnumeric(" 42 ", false), 8);
	ASSERT_FALSE(ms_strisnumeric("4 2", false), 9);
	ASSERT_FALSE(ms_strisnumeric(NULL, false), 10);
}
