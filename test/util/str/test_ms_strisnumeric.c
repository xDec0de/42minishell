/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strisnumeric.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:47:46 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:29:48 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_TRUE(ms_strisnumeric("42", true));
	ASSERT_TRUE(ms_strisnumeric("42", false));
	ASSERT_TRUE(ms_strisnumeric(" 42", true));
	ASSERT_TRUE(ms_strisnumeric("42 ", true));
	ASSERT_TRUE(ms_strisnumeric("\t 42 \t", true));
	ASSERT_FALSE(ms_strisnumeric(" 42", false));
	ASSERT_FALSE(ms_strisnumeric("42 ", false));
	ASSERT_FALSE(ms_strisnumeric(" 42 ", false));
	ASSERT_FALSE(ms_strisnumeric("4 2", false));
	ASSERT_FALSE(ms_strisnumeric(NULL, false));
}
