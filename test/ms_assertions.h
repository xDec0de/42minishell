/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_assertions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:53:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:46:35 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ASSERTIONS_H
# define MS_ASSERTIONS_H

/* stdout & fprintf */
#include <stdio.h>

/* strcmp */
#include <string.h>

/* exit */
#include <stdlib.h>

int __TEST_NUMBER__ = 0;

/*
 - Assertions - Bool
 */

#define ASSERT_TRUE(expr) do {\
	__TEST_NUMBER__++;\
	if (!(expr)) {\
		fprintf(stderr, "Got FALSE when expecting TRUE from %s", #expr);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

#define ASSERT_FALSE(expr) do {\
	__TEST_NUMBER__++;\
	if ((expr)) {\
		fprintf(stderr, "Got TRUE when expecting FALSE from %s", #expr);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

/*
 - Assertions - NULL
 */

#define ASSERT_NULL(expr) do {\
	__TEST_NUMBER__++;\
	if ((expr) != NULL) {\
		fprintf(stderr, "Got NOT NULL when expecting NULL from %s", #expr);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

#define ASSERT_NOT_NULL(expr) do {\
	__TEST_NUMBER__++;\
	if ((expr) == NULL) {\
		fprintf(stderr, "Got NULL when expecting NOT NULL from %s", #expr);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

/*
 - Assertions - Numeric
 */

#define ASSERT_INT_EQUALS(actual, expected) do {\
	__TEST_NUMBER__++;\
	int __aie_actual__ = (actual);\
	int __aie_expected__ = (expected);\
	if (__aie_actual__ != __aie_expected__) {\
		fprintf(stderr, "Got %i when expecting %i from %s", __aie_actual__, __aie_expected__, #actual);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

#define ASSERT_ULONG_EQUALS(actual, expected) do {\
	__TEST_NUMBER__++;\
	t_ulong __aue_actual__ = (actual);\
	t_ulong __aue_expected__ = (expected);\
	if (__aue_actual__ != __aue_expected__) {\
		fprintf(stderr, "Got %lld when expecting %lld from %s", __aue_actual__, __aue_expected__, #actual);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

/*
 - Assertions - String
 */

#define ASSERT_STR_EQUALS(actual, expected) do {\
	__TEST_NUMBER__++;\
	char *__ase_actual__ = (actual);\
	char *__ase_expected__ = (expected);\
	if (strcmp(__ase_actual__, __ase_expected__) != 0) {\
		fprintf(stderr, "Got \"%s\" when expecting \"%s\" from %s", __ase_actual__, __ase_expected__, #actual);\
		exit(__TEST_NUMBER__);\
	}\
} while (0)

#define FREE_ASSERT_STR_EQUALS(actual, expected) do {\
	__TEST_NUMBER__++;\
	char *__fase_actual__ = (actual);\
	char *__fase_expected__ = (expected);\
	if (strcmp(__fase_actual__, __fase_expected__) != 0) {\
		fprintf(stderr, "Got \"%s\" when expecting \"%s\" from %s", __fase_actual__, __fase_expected__, #actual);\
		exit(__TEST_NUMBER__);\
	}\
	free(__fase_actual__);\
} while (0)

#endif