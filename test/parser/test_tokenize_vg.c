/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenize_vg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:07:55 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/25 19:29:32 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "parser/parser.h"
#include "array_utils.h"

int	main(void)
{
	char	**token_arr;
	t_token	*tokens;
	t_token	*tmp;
	
	token_arr = to_token_array("echo \"Hello, World!\" | grep \'Hello\' > output.txt");
	tokens = tokenize(token_arr);
	tmp = tokens;
	ASSERT_NOT_NULL(tmp, 1);
	ASSERT_STR_EQUALS(tmp->value, "echo \"Hello, World!\"", 2);
	ASSERT_TRUE(tmp->type == T_PIPE, 3);
	tmp = tmp->next;
	ASSERT_NOT_NULL(tmp, 4);
	ASSERT_STR_EQUALS(tmp->value, "grep \'Hello\'", 5);
	ASSERT_TRUE(tmp->type == T_REDIR_OUT, 6);
	tmp = tmp->next;
	ASSERT_NOT_NULL(tmp, 7);
	ASSERT_STR_EQUALS(tmp->value, "output.txt", 8);
	ASSERT_TRUE(tmp->type == T_END, 9);
	ms_arrfree(token_arr);
	free_token_list(tokens);
}
