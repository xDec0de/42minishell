/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_arrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:56:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:27:28 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "array_utils.h"

int	main(void)
{
	char* arr[3] = {"Hello", "42", NULL};
	ASSERT_ULONG_EQUALS(ms_arrlen((void **) arr), 2L);
	ASSERT_ULONG_EQUALS(ms_arrlen(NULL), 0L);
	arr[0] = NULL;
	ASSERT_ULONG_EQUALS(ms_arrlen((void **) arr), 0L);
}
