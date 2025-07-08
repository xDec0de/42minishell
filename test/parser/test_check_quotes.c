/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 05:32:17 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:25:23 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "parser/parser.h"

int	main(void)
{
	ASSERT_TRUE(check_quotes("Hello world"));
	ASSERT_TRUE(check_quotes("\"Hello world\""));
	ASSERT_TRUE(check_quotes("'\"Hello world\"'"));
	ASSERT_FALSE(check_quotes("'\"Hello world\""));
}
