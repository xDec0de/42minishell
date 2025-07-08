/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_special_char_count.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:01:25 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:09:48 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "parser/parser.h"

int	main(void)
{
	ASSERT_FALSE(check_special_char_count("Hello || world"), 1);
	ASSERT_FALSE(check_special_char_count("Hello >>> world"), 2);
	ASSERT_TRUE(check_special_char_count("Hello >> world"), 3);
	ASSERT_TRUE(check_special_char_count("Hello > world"), 4);
	ASSERT_TRUE(check_special_char_count("Hello < world"), 5);
	ASSERT_TRUE(check_special_char_count("Hello << world"), 6);
	ASSERT_FALSE(check_special_char_count("Hello <<< world"), 7);
	ASSERT_TRUE(check_special_char_count(">> Hello <"), 8);
	ASSERT_FALSE(check_special_char_count(">| Hello <"), 9);
}
