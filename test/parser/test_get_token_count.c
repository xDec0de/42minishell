/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_token_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:21:22 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/22 01:28:06 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "parser/parser.h"

int	main(void)
{
	ASSERT_ULONG_EQUALS(get_token_count("echo Hello world"), 3L);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello world\""), 2L);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello 'world'\""), 2L);
	ASSERT_ULONG_EQUALS(get_token_count("echo \"Hello 'world'\" >> hello.txt"), 4L);
}
