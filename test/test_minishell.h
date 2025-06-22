/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:53:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/22 14:07:57 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MINISHELL_H
# define TEST_MINISHELL_H

#include "minishell.h"
#include <string.h>

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
	int __aie_actual__ = (actual);\
	int __aie_expected__ = (expected);\
	if (__aie_actual__ != __aie_expected__) {\
		fprintf(stderr, "Got %i when expecting %i", __aie_actual__, __aie_expected__);\
		exit(test_num);\
	}\
} while (0)

#define ASSERT_ULONG_EQUALS(actual, expected, test_num) do {\
	t_ulong __aue_actual__ = (actual);\
	t_ulong __aue_expected__ = (expected);\
	if (__aue_actual__ != __aue_expected__) {\
		fprintf(stderr, "Got %lld when expecting %lld", __aue_actual__, __aue_expected__);\
		exit(test_num);\
	}\
} while (0)

/*
 - Assertions - String
 */

#define ASSERT_STR_EQUALS(actual, expected, test_num) do {\
	char *__ase_actual__ = (actual);\
	char *__ase_expected__ = (expected);\
	if (strcmp(__ase_actual__, __ase_expected__) != 0) {\
		fprintf(stderr, "Got %s when expecting %s", __ase_actual__, __ase_expected__);\
		exit(test_num);\
	}\
} while (0)

#define FREE_ASSERT_STR_EQUALS(actual, expected, test_num) do {\
	char *__fase_actual__ = (actual);\
	ASSERT_STR_EQUALS(__fase_actual__, (expected), (test_num));\
	free(__fase_actual__);\
} while (0)

#endif