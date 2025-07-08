/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_itoa_vg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:00:26 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:28:15 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"
#include <limits.h>

int	main(void)
{
	FREE_ASSERT_STR_EQUALS(ms_itoa(42), "42");
	FREE_ASSERT_STR_EQUALS(ms_itoa(-42), "-42");
	FREE_ASSERT_STR_EQUALS(ms_itoa(0), "0");
	FREE_ASSERT_STR_EQUALS(ms_itoa(INT_MAX), "2147483647");
	FREE_ASSERT_STR_EQUALS(ms_itoa(INT_MIN), "-2147483648");
}
