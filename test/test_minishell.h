/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:53:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/15 16:32:55 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

#include "minishell.h"

/*
 - Utility macros
 */

# define _STR(x) #x
# define STR(x) _STR(x)

/*
 - Assertions - Bool
 */

#define ASSERT_TRUE(expr, test_num) do {\
	if (!(expr)) {\
		fprintf(stderr, "Got FALSE when expecting TRUE");\
		exit(test_num);\
	}\
} while (0)

#define ASSERT_FALSE(expr, test_num) do {\
	if ((expr)) {\
		fprintf(stderr, "Got TRUE when expecting FALSE");\
		exit(test_num);\
	}\
} while (0)

/*
 - Assertions - NULL
 */

#define ASSERT_NULL(expr, test_num) do {\
	if ((expr) != NULL) {\
		fprintf(stderr, "Got NOT NULL when expecting NULL");\
		exit(test_num);\
	}\
} while (0)

#define ASSERT_NOT_NULL(expr, test_num) do {\
	if ((expr) == NULL) {\
		fprintf(stderr, "Got NULL when expecting NOT NULL");\
		exit(test_num);\
	}\
} while (0)

/*
 - Assertions - Numeric
 */

#define ASSERT_INT_EQUALS(actual, expected, test_num) do {\
	if ((actual) != (expected)) {\
		fprintf(stderr, "Got %i when expecting %i", (actual), (expected));\
		exit(test_num);\
	}\
} while (0)

#define ASSERT_ULONG_EQUALS(actual, expected, test_num) do {\
	if ((actual) != (expected)) {\
		fprintf(stderr, "Got %ld when expecting %ld", (actual), (expected));\
		exit(test_num);\
	}\
} while (0)

#endif