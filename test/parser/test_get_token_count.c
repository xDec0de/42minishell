/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_token_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:21:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/17 16:52:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int	main(void)
{
	ASSERT_ULONG_EQUALS(get_token_count("echo Hello world"), 3L, 1);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello world\""), 2L, 2);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello 'world'\""), 2L, 3);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello 'world'\""), 2L, 4);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello 'world'\" >> hello.txt"), 4L, 5);
}
