/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_arrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:56:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/06/15 16:41:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell.h"

int	main(void)
{
	char* arr[3] = {"Hello", "42", NULL};
	ASSERT_ULONG_EQUALS(ms_arrlen((void **) arr), 2L, 1);
	ASSERT_ULONG_EQUALS(ms_arrlen(NULL), 0L, 2);
	arr[0] = NULL;
	ASSERT_ULONG_EQUALS(ms_arrlen((void **) arr), 0L, 3);
}
