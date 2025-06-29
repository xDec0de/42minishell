/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenize_vg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:07:55 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/30 00:29:38 by daniema3         ###   ########.fr       */
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
	ASSERT_STR_EQUALS(tmp->cmd, "echo", 2);
	ASSERT_STR_EQUALS(tmp->args[0], "Hello, World!", 3);
	ASSERT_TRUE(tmp->type == T_PIPE, 4);
	tmp = tmp->next;
	ASSERT_NOT_NULL(tmp, 5);
	ASSERT_STR_EQUALS(tmp->cmd, "grep", 6);
	ASSERT_STR_EQUALS(tmp->args[0], "\'Hello\'", 7);
	ASSERT_TRUE(tmp->type == T_REDIR_OUT, 8);
	tmp = tmp->next;
	ASSERT_NOT_NULL(tmp, 9);
	ASSERT_STR_EQUALS(tmp->cmd, "output.txt", 10);
	ASSERT_NULL(tmp->args[0], 11);
	ASSERT_TRUE(tmp->type == T_END, 12);
	ms_arrfree(token_arr);
	free_token_list(tokens);
	// One token only
	token_arr = to_token_array("echo \"Hello, World!\"");
	tokens = tokenize(token_arr);
	ASSERT_NOT_NULL(tokens, 13);
	ASSERT_STR_EQUALS(tokens->cmd, "echo", 14);
	ASSERT_STR_EQUALS(tokens->args[0], "Hello, World!", 15);
	ASSERT_TRUE(tokens->type == T_END, 16);
	ms_arrfree(token_arr);
	free_token_list(tokens);
	// No args
	token_arr = to_token_array("echo");
	tokens = tokenize(token_arr);
	ASSERT_NOT_NULL(tokens, 17);
	ASSERT_STR_EQUALS(tokens->cmd, "echo", 18);
	ASSERT_NULL(tokens->args[0], 19);
	ms_arrfree(token_arr);
	free_token_list(tokens);
}
