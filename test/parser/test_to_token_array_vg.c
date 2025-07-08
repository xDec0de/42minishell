/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_token_array_vg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:19:05 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:26:16 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "array_utils.h"
#include "parser/parser.h"

int	main(void)
{
	char	**tokens;

	// Mixed quotes
	tokens = to_token_array("echo \"Hello, World!\" | grep \'Hello\' > output.txt");
	ASSERT_NOT_NULL(tokens);
	ASSERT_STR_EQUALS(tokens[0], "echo");
	ASSERT_STR_EQUALS(tokens[1], "Hello, World!");
	ASSERT_STR_EQUALS(tokens[2], "|");
	ASSERT_STR_EQUALS(tokens[3], "grep");
	ASSERT_STR_EQUALS(tokens[4], "\'Hello\'");
	ASSERT_STR_EQUALS(tokens[5], ">");
	ASSERT_STR_EQUALS(tokens[6], "output.txt");
	ms_arrfree(tokens);
	// All special characters
	tokens = to_token_array("just | split > it < right >> please << :)");
	ASSERT_NOT_NULL(tokens);
	ASSERT_STR_EQUALS(tokens[0], "just");
	ASSERT_STR_EQUALS(tokens[1], "|");
	ASSERT_STR_EQUALS(tokens[2], "split");
	ASSERT_STR_EQUALS(tokens[3], ">");
	ASSERT_STR_EQUALS(tokens[4], "it");
	ASSERT_STR_EQUALS(tokens[5], "<");
	ASSERT_STR_EQUALS(tokens[6], "right");
	ASSERT_STR_EQUALS(tokens[7], ">>");
	ASSERT_STR_EQUALS(tokens[8], "please");
	ASSERT_STR_EQUALS(tokens[9], "<<");
	ASSERT_STR_EQUALS(tokens[10], ":)");
	ms_arrfree(tokens);
}
