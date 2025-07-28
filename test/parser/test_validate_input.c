/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validate_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:41:18 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/28 16:44:31 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ms_assertions.h"

int main()
{
	// Special char count
	ASSERT_FALSE(validate_input("Hello || world"));
	ASSERT_FALSE(validate_input("Hello >>> world"));
	ASSERT_TRUE(validate_input("Hello >> world"));
	ASSERT_TRUE(validate_input("Hello > world"));
	ASSERT_TRUE(validate_input("Hello < world"));
	ASSERT_TRUE(validate_input("Hello << world"));
	ASSERT_FALSE(validate_input("Hello <<< world"));
	ASSERT_FALSE(validate_input(">> Hello <"));
	ASSERT_FALSE(validate_input(">| Hello <"));
	// Empty tokens
	ASSERT_FALSE(validate_input("Hello |"));
	ASSERT_FALSE(validate_input("echo a | | cat -e"));
	// Quotes
	ASSERT_TRUE(validate_input("Hello world"));
	ASSERT_TRUE(validate_input("\"Hello world\""));
	ASSERT_TRUE(validate_input("'\"Hello world\"'"));
	ASSERT_FALSE(validate_input("'\"Hello world\""));
}
