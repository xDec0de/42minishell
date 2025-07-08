/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ms_substr_vg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:30:08 by daniema3          #+#    #+#             */
/*   Updated: 2025/07/08 13:30:30 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_assertions.h"
#include "str_utils.h"

int	main(void)
{
	ASSERT_NULL(ms_substr(NULL, 0, 0));
	FREE_ASSERT_STR_EQUALS(ms_substr("Hello, World!", 0, 5), "Hello");
	FREE_ASSERT_STR_EQUALS(ms_substr("Hello, World!", 7, 42), "World!");
	FREE_ASSERT_STR_EQUALS(ms_substr("Hello", 10, 5), "");

}
