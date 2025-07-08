/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_special_char_count.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:01:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:25:36 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "parser/parser.h"

int	main(void)
{
	ASSERT_FALSE(check_special_char_count("Hello || world"));
	ASSERT_FALSE(check_special_char_count("Hello >>> world"));
	ASSERT_TRUE(check_special_char_count("Hello >> world"));
	ASSERT_TRUE(check_special_char_count("Hello > world"));
	ASSERT_TRUE(check_special_char_count("Hello < world"));
	ASSERT_TRUE(check_special_char_count("Hello << world"));
	ASSERT_FALSE(check_special_char_count("Hello <<< world"));
	ASSERT_TRUE(check_special_char_count(">> Hello <"));
	ASSERT_FALSE(check_special_char_count(">| Hello <"));
}
