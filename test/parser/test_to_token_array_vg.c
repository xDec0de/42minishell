/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to_token_array_vg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:19:05 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 16:01:00 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "array_utils.h"
#include "parser/parser.h"

int	main(void)
{
	char	**tokens;
	
	tokens = to_token_array("echo \"Hello, World!\" | grep \'Hello\' > output.txt");
	ASSERT_NOT_NULL(tokens, 1);
	ASSERT_STR_EQUALS(tokens[0], "echo", 2);
	ASSERT_STR_EQUALS(tokens[1], "\"Hello, World!\"", 3);
	ASSERT_STR_EQUALS(tokens[2], "|", 4);
	ASSERT_STR_EQUALS(tokens[3], "grep", 5);
	ASSERT_STR_EQUALS(tokens[4], "\'Hello\'", 6);
	ASSERT_STR_EQUALS(tokens[5], ">", 7);
	ASSERT_STR_EQUALS(tokens[6], "output.txt", 8);
	ms_arrfree(tokens);
}
