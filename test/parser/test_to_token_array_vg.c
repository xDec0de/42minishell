/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_token_array_vg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:19:05 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/27 18:19:02 by daniema3         ###   ########.fr       */
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
	ASSERT_NOT_NULL(tokens, 1);
	ASSERT_STR_EQUALS(tokens[0], "echo", 2);
	ASSERT_STR_EQUALS(tokens[1], "Hello, World!", 3);
	ASSERT_STR_EQUALS(tokens[2], "|", 4);
	ASSERT_STR_EQUALS(tokens[3], "grep", 5);
	ASSERT_STR_EQUALS(tokens[4], "\'Hello\'", 6);
	ASSERT_STR_EQUALS(tokens[5], ">", 7);
	ASSERT_STR_EQUALS(tokens[6], "output.txt", 8);
	ms_arrfree(tokens);
	// All special characters
	tokens = to_token_array("just | split > it < right >> please << :)");
	ASSERT_NOT_NULL(tokens, 1);
	ASSERT_STR_EQUALS(tokens[0], "just", 9);
	ASSERT_STR_EQUALS(tokens[1], "|", 10);
	ASSERT_STR_EQUALS(tokens[2], "split", 11);
	ASSERT_STR_EQUALS(tokens[3], ">", 12);
	ASSERT_STR_EQUALS(tokens[4], "it", 13);
	ASSERT_STR_EQUALS(tokens[5], "<", 14);
	ASSERT_STR_EQUALS(tokens[6], "right", 15);
	ASSERT_STR_EQUALS(tokens[7], ">>", 16);
	ASSERT_STR_EQUALS(tokens[8], "please", 17);
	ASSERT_STR_EQUALS(tokens[9], "<<", 18);
	ASSERT_STR_EQUALS(tokens[10], ":)", 19);
	ms_arrfree(tokens);
}
