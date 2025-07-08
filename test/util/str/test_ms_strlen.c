/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 01:42:07 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:30:04 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_ULONG_EQUALS(ms_strlen(NULL), 0L);
	ASSERT_ULONG_EQUALS(ms_strlen(""), 0L);
	ASSERT_ULONG_EQUALS(ms_strlen("Hi"), 2L);
}
