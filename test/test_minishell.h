/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:53:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/13 01:52:11 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

#include "unity.h"
#include "minishell.h"

/*
 - util/char
 */

void	test_ms_isdigit(void);

/*
 - util/str
 */

void	test_ms_strlen(void);

/*
 - Utility macros
 */

# define _STR(x) #x
# define STR(x) _STR(x)

/*
 - Assertions
 */

# define ASSERT_TRUE(expr, num) \
	TEST_ASSERT_TRUE_MESSAGE((expr), STR(num))

# define ASSERT_FALSE(expr, num) \
	TEST_ASSERT_FALSE_MESSAGE((expr), STR(num))

# define ASSERT_INT_EQUALS(actual, expected, num) \
	TEST_ASSERT_EQUAL_INT_MESSAGE((expected), (actual), STR(num))

#endif