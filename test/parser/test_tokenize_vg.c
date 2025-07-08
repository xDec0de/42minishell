/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenize_vg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:07:55 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:26:56 by daniema3         ###   ########.fr       */
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
	ASSERT_NOT_NULL(tmp);
	ASSERT_STR_EQUALS(tmp->cmd, "echo");
	ASSERT_STR_EQUALS(tmp->args[0], "Hello, World!");
	ASSERT_TRUE(tmp->type == T_PIPE);
	tmp = tmp->next;
	ASSERT_NOT_NULL(tmp);
	ASSERT_STR_EQUALS(tmp->cmd, "grep");
	ASSERT_STR_EQUALS(tmp->args[0], "\'Hello\'");
	ASSERT_TRUE(tmp->type == T_REDIR_OUT);
	tmp = tmp->next;
	ASSERT_NOT_NULL(tmp);
	ASSERT_STR_EQUALS(tmp->cmd, "output.txt");
	ASSERT_NULL(tmp->args[0]);
	ASSERT_TRUE(tmp->type == T_END);
	ms_arrfree(token_arr);
	free_token_list(tokens);
	// One token only
	token_arr = to_token_array("echo \"Hello, World!\"");
	tokens = tokenize(token_arr);
	ASSERT_NOT_NULL(tokens);
	ASSERT_STR_EQUALS(tokens->cmd, "echo");
	ASSERT_STR_EQUALS(tokens->args[0], "Hello, World!");
	ASSERT_TRUE(tokens->type == T_END);
	ms_arrfree(token_arr);
	free_token_list(tokens);
	// No args
	token_arr = to_token_array("echo");
	tokens = tokenize(token_arr);
	ASSERT_NOT_NULL(tokens);
	ASSERT_STR_EQUALS(tokens->cmd, "echo");
	ASSERT_NULL(tokens->args[0]);
	ms_arrfree(token_arr);
	free_token_list(tokens);
}
